#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=1e6+10;
const ll inf=0x3f3f3f3f3f3f3f3f;

int a[mn];
int f[mn];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int tc;
    cin>>tc;
    while(tc--){
    	string s;
    	cin>>s;
    	int n=s.size();
    	for(int i=0;i<=n+1;i++)f[i]=0x3f3f3f3f,a[i]=0;
    	s=" "+s;
    	for(int i=1;i<=n;i++)a[i]=a[i-1]+(s[i]=='+'?1:-1);
    	for(int i=1;i<=n;i++)if(a[i]<0)f[-a[i]]=min(f[-a[i]],i);
    	ll ans=0;
    	for(int i=1;f[i]!=0x3f3f3f3f;i++)ans+=f[i];
    	printf("%lld\n",ans+n);
    }
}