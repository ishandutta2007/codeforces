#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int M=3e5+9;
int n;
int u[M],v[M],p[M],d[M];
int main(){
    cin>>n;
    for(int i=1;i<=n;++i)cin>>u[i]>>v[i],p[u[i]]=v[i],p[v[i]]=u[i];
    for(int i=1;i<=n*2;++i){
        if(!d[i]){
            int x=i,o=1;
            d[x]=o;
            x=p[x];
            while(x!=i){
                if(o==1){
                    d[x]=2;
                    x=x^1;
                    o=2;
                }
                else{
                    d[x]=1;
                    x=p[x];
                    o=1;
                }
            }
        }
    }
    for(int i=1;i<=n;++i)cout<<d[u[i]]<<" "<<d[v[i]]<<endl;
    return 0;
}
/*
1
2
codeforces
technocup

*/