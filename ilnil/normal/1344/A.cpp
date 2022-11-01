#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=2e5+5,mo=1e9+7;
int t,n,ans,yes;
int a[N];
int cnt[N];
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n;
		fo(i,0,n-1)cin>>a[i];
		fo(i,0,n-1)cnt[i]=0;
		yes=1;
		fo(i,0,n-1)cnt[((i+a[i])%n+n)%n]++;
		fo(i,0,n-1)if(cnt[i]!=1)yes=0;
		printf(yes?"YES\n":"NO\n");
	}
	
}