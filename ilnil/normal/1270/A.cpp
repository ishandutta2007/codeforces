#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
using namespace std;
const int N=1e5+5;
int n,t,k1,k2;
int mx1,mx2,a;
int ans;
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	for(;t--;){
		cin>>n>>k1>>k2;
		mx1=mx2=0;
		fo(i,1,k1)cin>>a,mx1=max(mx1,a);
		fo(i,1,k2)cin>>a,mx2=max(mx2,a);
		printf(mx1>mx2?"YES\n":"NO\n");
	}
}