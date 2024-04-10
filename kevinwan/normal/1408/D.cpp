#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=1e6+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
int a[mn],b[mn],c[mn],d[mn];
int h[mn];
int main(){
	#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i]>>b[i];
    for(int i=0;i<m;i++)cin>>c[i]>>d[i];
    memset(h,-1,sizeof(h));
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
    	if(c[j]-a[i]<0||d[j]-b[i]<0)continue;
    	h[c[j]-a[i]]=max(h[c[j]-a[i]],d[j]-b[i]);
    }
    int ans=0x3f3f3f3f;
    for(int i=mn-2;i>=0;i--)h[i]=max(h[i],h[i+1]);
    for(int i=0;i<mn;i++)ans=min(ans,i+h[i]+1);
    printf("%d\n",ans);
}