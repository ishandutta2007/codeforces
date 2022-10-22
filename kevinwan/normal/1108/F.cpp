#include<bits/stdc++.h>
using namespace std;
const int mn=2e5+10;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(b);i>(a);i--)
struct edge{int a,b,c;const bool operator<(const edge&ot)const{return c<ot.c;}};
edge e[mn];
int p[mn],num;
int f(int x){return x==p[x]?x:(p[x]=f(p[x]));}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    FOR(i,0,m){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        e[i]={a,b,c};
    }
    sort(e,e+m);
    FOR(i,0,n+1)p[i]=i;
    int ans=0;
    int i,j;
    for(i=0;i<m;){
        vector<int> cont;
        int u=0;
        for(j=i;j<m&&e[i].c==e[j].c;j++){
            if(f(e[j].a)!=f(e[j].b))cont.push_back(j);
        }
        i=j;
        for(int j:cont){
            if(f(e[j].a)!=f(e[j].b))u++;
            p[f(e[j].a)]=f(e[j].b);
        }
        ans+=cont.size()-u;
    }
    printf("%d",ans);
}