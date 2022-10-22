#include <bits/stdc++.h>
using namespace std;

const int N=105;
int x[N],y[N];
vector <int> graf[N];
bool tooch[N];

void dfs(int v){
    tooch[v]=1;
    for(auto c: graf[v]){
        if(tooch[c]==0)dfs(c);
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    int n,br=0,i,j;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(x[i]==x[j] || y[i]==y[j]){graf[i].push_back(j);graf[j].push_back(i);}
        }
    }
    for(i=0;i<n;i++){
        if(tooch[i]==0){
            br++;
            dfs(i);
        }
    }
    cout<<br-1;
    return 0;
}