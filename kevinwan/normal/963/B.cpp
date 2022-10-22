#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mn=2e5+10;
vector<int> g[mn];
int pr[mn],mi[mn];
vector<int> ans;
bool s[mn],done[mn];
void kill(int x,int p){
    if(done[x])return;
    done[x]=1;
    ans.push_back(x);
    for(int y:g[x]){
        if((!s[x]&&y==p)||(y!=p&&s[y]))pr[y]--;
        mi[y]++;
    }
}
void dfs(int x,int p){
    s[x]=1;
    for(int y:g[x]){
        if(y==p)continue;
        dfs(y,x);
        s[x]^=s[y];
        if(!s[y])pr[x]++;
    }
    if(p&&s[x])pr[x]++;
}
void dfs2(int x,int p){
    if(done[x])return;
    if((g[x].size()-mi[x])%2==0&&pr[x]==0&&!done[x])kill(x,p);
    for(int y:g[x]){
        if(y==p)continue;
        dfs2(y,x);
        if((g[x].size()-mi[x])%2==0&&pr[x]==0&&!done[x])kill(x,p);
    }
    if(done[x]){
        for(int y:g[x])if(y!=p)dfs2(y,x);
    }
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,i;
    cin>>n;
    if(!(n&1)){printf("NO");return 0;}
    for(i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x==0);
        else{
            g[i].push_back(x);
            g[x].push_back(i);
        }
    }
    dfs(1,0);
    dfs2(1,0);
    if(ans.size()==n){
            printf("YES");
            for(int x:ans){
                printf("\n%d",x);
            }
    }
    else printf("NO");
}