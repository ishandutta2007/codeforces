#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int mn=3e5+10;
const ll mod=1e9+7;
ll a[mn];
map<int,int>s[mn];
int main(){
    int n;
    scanf("%d",&n);
    ll ans=0;
    for(int i=1;i<=n;i++)scanf("%lld",a+i),ans+=a[i];
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        if(s[u][v]!=0){
            int ww=s[u][v];
            a[ww]++;
            if(a[ww]>=1)ans++;
        }
        if(w!=0){
            if(a[w]>=1)ans--;
            a[w]--;
        }
        s[u][v]=w;
        printf("%lld\n",ans);
    }
}