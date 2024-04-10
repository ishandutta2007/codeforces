#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 2e5+7;
int cnt[N];
ll lcm(ll a,ll b){
	return a/__gcd(a,b)*b;
}
void solve(){
	int l,r;
	cin>>l>>r;
	ll len = r-l+1;
	ll res = len*(len-1)*(len-2)/6;
	for(int i = l;i<=r;i+=1){
		for(int j = i*2;j<=r;j+=i){
			cnt[j] += 1;
		}
		for(int j = i*2;j<=r*2;j+=i){
			if (j%6==0 && i<j/3 && i+j/2+j/3>j){
				res -= 1;
			}
		}
	}
	for(int i = l;i<=r;i+=1){
		res -= cnt[i]*(cnt[i]-1)/2;
		cnt[i] = 0;
	}
	cout<<res<<endl;
}
signed main(){
	
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt = 1;
	cin>>tt;
	while(tt--){
		solve();
	}
}