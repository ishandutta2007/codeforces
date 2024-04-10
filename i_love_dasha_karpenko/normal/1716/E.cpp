#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';
const int N = 19;
const int SZ = 1<<N;
const int SQRT = 1<<(N/2);
struct block{
	ll l,r,sum,mx;
	block(){
		l = 0,r = 0,sum = 0,mx = 0;
	}
} B[SQRT][SQRT];
int A[SZ];
void build(int bl,int l,int r){
	for(int mask = 0;mask<r-l;mask+=1){
		ll sum = 0,mx = 0,csum = 0;
		for(int i = l;i<r;i+=1){
			csum += A[i^mask];
			csum = max(csum,0ll);
			mx = max(mx,csum);
			B[bl][mask].sum += A[i^mask];
			sum += A[i^mask];
			B[bl][mask].l = max(B[bl][mask].l,sum);
		}
		sum = 0;
		for(int i = r-1;i>=l;i-=1){
			sum += A[i^mask];
			B[bl][mask].r = max(B[bl][mask].r,sum);
		}
		B[bl][mask].mx = mx;
	}
}
int state = 0;
ll recalc(int n){
	int lmask = state&((1<<(n/2))-1);
	int umask = state>>(n/2);
	ll res = 0;
	ll pre = 0,sum = 0;
	for(int i = 0;i<(1<<(n-n/2));i+=1){
		res = max(res,pre + sum + B[i^umask][lmask].l);
		sum += B[i^umask][lmask].sum;
		pre = max(pre,-sum + B[i^umask][lmask].r);
		res = max(res,B[i^umask][lmask].mx);
	}
	return res;
}
void solve(){
	int n;
	cin>>n;
	int bsz = n/2;
	for(int i = 0;i<(1<<n);i+=1){
		cin>>A[i];
	}
	for(int bl = 0;(bl<<bsz)<(1<<n);bl+=1){
		build(bl,bl<<bsz,(bl+1)<<bsz);
	}
	int q;
	cin>>q;
	for(int qe = 1;qe<=q;qe+=1){
		int k;
		cin>>k;
		state ^= 1<<k;
		cout<<recalc(n)<<endl;
	}
}
signed main(){
	
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt = 1;
//	cin>>tt;
	while(tt--){
		solve();
	}
}