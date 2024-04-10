#include <bits/stdc++.h>
using namespace std;

vector <int> ljudi[105];
vector <int> graf[105];
bool tooch[105];

void dfs(int v){
    tooch[v]=1;
    for(auto c : graf[v]){
        if(tooch[c]==0)dfs(c);
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    int n,m,br=0,i,k[105],j,r,brk=0;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>k[i];
        for(j=1;j<=k[i];j++){
            cin>>r;
            ljudi[r].push_back(i);
        }
        if(k[i]==0)brk++;
    }
    for(i=1;i<=m;i++){
        for(auto c : ljudi[i]){
            for(auto p : ljudi[i]){
                if(c!=p){
                    graf[c].push_back(p);
                    graf[p].push_back(c);
                }
            }
        }
    }
    for(i=1;i<=n;i++){
        if(!tooch[i] && k[i]!=0){
            br++;
            dfs(i);
        }
    }
    cout<<max(0,br-1)+brk;
    return 0;
}