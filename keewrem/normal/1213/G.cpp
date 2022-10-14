#include <bits/stdc++.h>
using namespace std;
#define MAXN 200002
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<pii> vp;
int uf[MAXN], N,Q,a,b,c,ind;
ll res;
ll siz[MAXN];
vector <pair<int,pii>> edges;
vp queries;
int find(int a){
    if(uf[a]!=a)uf[a]=find(uf[a]);
    return uf[a];
}
void dsunion(int a, int b){
    a = find(a); b = find(b);
    res-=((siz[a]-1)*siz[a])/2;
    res-=((siz[b]-1)*siz[b])/2;
    if(siz[a]<siz[b])swap(a,b);
    siz[a]+=siz[b]; uf[b]=a;
    res+=((siz[a]-1)*siz[a])/2;
}

int main(){
    scanf("%d %d",&N,&Q);
    for(int i = 0; i <= N; i++){siz[i]=1;uf[i]=i;}
    for(int i = 0; i < N-1; i++){
        scanf("%d %d %d", &a, &b, &c);
        edges.push_back({c,{a,b}});
    }
    sort(edges.begin(),edges.end());
    for(int i = 0; i < Q; i++){
        scanf("%d", &a);
        queries.push_back({a,i});
    }
    ll sas[Q];
    sort(queries.begin(),queries.end());
    for(auto x: queries){
        while(ind < N-1 && edges[ind].fi<=x.fi){
            dsunion(edges[ind].se.fi,edges[ind].se.se);
            ind++;
        }
        sas[x.se]=res;
    }
    for(int i = 0; i < Q; i++)printf("%lld ",sas[i]);
    return 0;
}