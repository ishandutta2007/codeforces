#include <bits/stdc++.h>

using namespace std;
const int N=2005;
vector <long> graf[N];
long br=0,brmax=0,brp=0;
void dfs(long v){
    br++;
    int sig=0;
    brp=br;
    for(auto c:graf[v]){
        dfs(c);
        sig=1;
    }
    if(sig==0)brmax=max(brmax,brp);
    br--;
}
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr),cerr.tie(nullptr);

    long n,i,x[N];
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>x[i];
        if(x[i]!=-1){
            graf[x[i]].push_back(i);
        }
    }
    for(i=1;i<=n;i++){
        if(x[i]==-1){
            br=0;
            dfs(i);
            brmax=max(brmax,br);
        }
    }
    cout<<brmax;
    return 0;
}