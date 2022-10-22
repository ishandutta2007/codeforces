#include <bits/stdc++.h>

using namespace std;
vector <long long> drvo[10000];
long long c[10005];
long long cs[10005];
long br=0;
int bio[10005];
void dfs(long r){
    bio[r]=1;
    if(cs[r]!=c[r]){c[r]=cs[r];br++;}
    for(auto v:drvo[r]){
            c[v]=c[r];
            dfs(v);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    long n,x,i;
    cin>>n;
    for(i=2;i<=n;i++){
        cin>>x;
        drvo[x].push_back(i);
    }
    for(i=1;i<=n;i++){
        cin>>cs[i];
    }
    dfs(1);
    cout<<br;
    return 0;
}