#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=3e5+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
int v[mn],ln[mn],s[mn],ans[mn];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int tc;
    cin>>tc;
    for(int tcc=1;tcc<=tc;tcc++){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>v[i];
        memset(ln,0,sizeof(ln[0])*(n+1));
    	memset(s,0,sizeof(ln[0])*(n+1));
    	memset(ans,0x3f,sizeof(ln[0])*(n+1));
    	for(int i=1;i<=n;i++){
    		s[v[i]]=max(s[v[i]],i-ln[v[i]]);
    		ln[v[i]]=i;
    	}
    	for(int i=1;i<=n;i++)s[i]=max(s[i],n+1-ln[i]);
    	for(int i=1;i<=n;i++)ans[s[i]]=min(ans[s[i]],i);
    	for(int i=1;i<n;i++)ans[i+1]=min(ans[i+1],ans[i]);
    	for(int i=1;i<=n;i++)printf("%d ",ans[i]==inf?-1:ans[i]);
    	printf("\n");
    }
}