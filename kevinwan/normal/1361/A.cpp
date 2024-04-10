#include<bits/stdc++.h>
using namespace std;
const int mn=5e5+10;
vector<int>g[mn];
int v[mn];
bool val[mn];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++)cin>>v[i];
    for(int i=1;i<=n;i++){
        bool f=0;
        if(g[i].size()<v[i]-1){
            printf("-1");
            return 0;
        }
        for(int j=1;j<v[i];j++)val[j]=0;
        for(int j:g[i]){
            val[v[j]]=1;
            if(v[j]==v[i])f=1;
        }
        bool m=1;
        for(int j=1;j<v[i];j++)m&=val[j];
        if(f||!m){printf("-1");return 0;}
    }
    vector<int>o(n);
    iota(o.begin(),o.end(),1);
    sort(o.begin(),o.end(),[](int a,int b){return v[a]<v[b];});
    for(int x:o)printf("%d ",x);
}