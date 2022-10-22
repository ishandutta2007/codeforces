#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=1e5+10;
int s[mn];
vector<int>g[mn];
int main(){
    int n,m,q;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        if(a>b)swap(a,b);
        g[a].push_back(b);
        s[a]++,s[b]++;
    }
    ll ans=0;
    for(int i=1;i<=n;i++)ans+=1LL*g[i].size()*(s[i]-g[i].size());
    printf("%lld\n",ans);
    scanf("%d",&q);
    while(q--){
        int x;
        scanf("%d",&x);
        ans-=1LL*g[x].size()*(s[x]-g[x].size());
        for(int y:g[x]){
            ans+=s[y]-2*(int)g[y].size()-1;
            g[y].push_back(x);
        }
        g[x].clear();
        printf("%lld\n",ans);
    }
}