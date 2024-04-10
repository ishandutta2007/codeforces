#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 555
int i,j,k,n,m,t,a[300500],f[300500],res[300500],r,l;
struct SB{
	int l,r,w,id;
	bool operator<(const SB x)const{
		if((l/N)!=(x.l/N))return l<x.l;
		return r<x.r;
	}
}q[300500];
int main() {
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()+1);
	memset(res,0x3f,sizeof(res));
	ios::sync_with_stdio(0);
	cin>>n>>t;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=t;i++){
		cin>>q[i].l>>q[i].r>>q[i].w;
		q[i].id=i;
	}
	sort(q+1,q+t+1);
	for(i=1;i<=t;i++){
		while(l<q[i].l)f[a[l++]]--;
		while(l>q[i].l)f[a[--l]]++;
		while(r<q[i].r)f[a[++r]]++;
		while(r>q[i].r)f[a[r--]]--;
		for(j=1;j<=100;j++){
			uniform_int_distribution<int>lim(1,r-l+1);
			k=l-1+lim(rng);
			if(f[a[k]]>((r-l+1)/q[i].w))res[q[i].id]=min(res[q[i].id],a[k]);
		}
	}
	for(i=1;i<=t;i++){
		cout<<((res[i]>1e9)?-1:res[i])<<'\n';
	}
}