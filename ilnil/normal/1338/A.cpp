#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=1e5+5,mo=1e9+7;
int t,n;
int ans;
int a[N];
ll v,mx;
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	for(;t--;){
		cin>>n;
		fo(i,1,n)cin>>a[i];
		ans=0;
		v=mx=0;
		fo(i,2,n){
			v+=a[i-1]-a[i];
			v=max(v,0LL);
			mx=max(mx,v);
		}
		for(;(1LL<<ans)<=mx;)++ans;
		printf("%d\n",ans);
	}
}