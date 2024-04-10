#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
int i,j,k,n,m;
int X[maxn],Y[maxn],Fa[maxn],P[maxn],c[maxn],d[maxn];
int find(int x){
    return Fa[x]==x?x:Fa[x]=find(Fa[x]);
}
bool check(){
    for(int i=1;i<=n;i++)Fa[i]=i;
    for(int i=1;i<=m;i++){
        if(find(X[P[i]])!=find(Y[P[i]])){
            c[i]=0;
            Fa[find(X[P[i]])]=Y[P[i]];
        }else c[i]=1;
    }
    if(m==n+2){
        vector<int>V;
        for(int i=1;i<=m;i++)
            if(c[i]==1)V.push_back(i);
            // 1,2  1,3  2,3
        for(int I=0;I<=2;I++)
            for(int J=0;J<=2;J++){
                if(I==J)continue;
                int K=3-I-J;
                if(X[P[V[I]]]==X[P[V[J]]] && Y[P[V[I]]]==X[P[V[K]]] && Y[P[V[J]]]==Y[P[V[K]]])return false;
            }
    }
    for(i=1;i<=m;i++)d[P[i]]=c[i];
    for(i=1;i<=m;i++)putchar('0'+d[i]);
    return true;
}
int Ans,ANS[maxn];
void dfs(int x){
    if(x>m){
        int Num=n+n;
        for(int i=1;i<=n;i++)Fa[i]=i;
        for(int i=1;i<=m;i++)
            if(!P[i])if(find(X[i])!=find(Y[i]))Fa[find(X[i])]=Y[i],Num--;
        for(int i=1;i<=n;i++)Fa[i]=i;
        for(int i=1;i<=m;i++)
            if(P[i])if(find(X[i])!=find(Y[i]))Fa[find(X[i])]=Y[i],Num--;
        if(Num<Ans){
            // cerr<<"Num="<<Num<<endl;
            // for(int i=1;i<=m;i++)cerr<<P[i]<<endl;
            Ans=Num;
            for(int i=1;i<=m;i++)ANS[i]=P[i];
        }
        return;
    }
    P[x]=0;
    dfs(x+1);
    P[x]=1;
    dfs(x+1);
}
int main(){
    int T;
    cin>>T;
    while(T--){
        scanf("%d%d",&n,&m);
        for(i=1;i<=m;i++){
            scanf("%d%d",&X[i],&Y[i]);
            if(X[i]>Y[i])swap(X[i],Y[i]);
        }
        if(n>=5){
            for(i=1;i<=m;i++)P[i]=i;
            do{
                if(check())break;
                random_shuffle(P+1,P+1+m);
            }while(1);
        }else{
            Ans=1e9;
            dfs(1);
            for(i=1;i<=m;i++)putchar(ANS[i]+'0');
        }puts("");
    }
}
/*
5 7
1 2
2 3
3 4
4 5
5 1
1 3
3 5
*/