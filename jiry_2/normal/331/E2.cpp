#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<deque>
#include<queue>
using namespace std;
struct bian{
    int u,v;
    vector<int>A;
    void scan(){
        scanf("%d%d",&u,&v); int k1; scanf("%d",&k1);
        for (int i=1;i<=k1;i++){int k2; scanf("%d",&k2); A.push_back(k2);}
    }
}A[2500];
struct atom{
    int u,v,len;
}B[10000],C[10000],D[10000],E[10000];
int b[60][60],n,m,len,pd[2500],now,f[120][60][60],w[120][60][60],mo=1e9+7,now2,bo[2500],g[120][60];
deque<int>Q,pre,next;
int check(int k){
    for (int i=0;i+1<A[k].A.size();i++)
        if (A[k].A[i]==A[k].u&&A[k].A[i+1]==A[k].v) return 1;
    return 0;
}
int solvel(int k){
    Q.push_front(k);
    if (Q.size()>2*n) return 0;
    if (pre.size()==0) return 1;
    int k1=pre.front();
//  cout<<"solvel "<<k<<" "<<k1<<endl;
    if (b[k1][k]){
        int k2=b[k1][k]; if (pd[k2]) return 0;
        for (int i=(A[k2].A.size())-1;i>=0;i--) pre.push_back(A[k2].A[i]);
        pre.pop_front(); return solvel(k1);
    }
    return 0;
}
int solver(int k){
//  cout<<"solver "<<k<<endl;
    Q.push_back(k);
    if (Q.size()>2*n) return 0;
    if (next.size()==0) return 1;
    int k1=next.front();
    if (b[k][k1]){
        int k2=b[k][k1];
        for (int i=0;i<A[k2].A.size();i++) next.push_back(A[k2].A[i]);
        next.pop_front(); return solver(k1);
    }
    return 0;
}
int solver2(int k){
//  cout<<"solver2 "<<k<<endl;
    Q.push_back(k);
    if (Q.size()>2*n) return 0;
    if (next.size()==0) return 1;
    int k1=next.front();
    if (b[k1][k]){
        int k2=b[k1][k];// if (pd[k2]) return 0;
        for (int i=(A[k2].A.size())-1;i>=0;i--) next.push_back(A[k2].A[i]);
        next.pop_front(); return solver2(k1);
    }
    return 0;
}
int main(){
    scanf("%d%d",&n,&m); 
    for (int i=1;i<=m;i++){
        A[i].scan(); b[A[i].u][A[i].v]=i; pd[i]=check(i);
    }
    for (int i=1;i<=m;i++)
        for (int j=0;j+1<A[i].A.size();j++)
            if (A[i].A[j]==A[i].u&&A[i].A[j+1]==A[i].v){
            //  cout<<i<<endl;
                Q.clear(); pre.clear(); next.clear();
                for (int k1=0;k1<j;k1++) pre.push_front(A[i].A[k1]);
                for (int k1=j+2;k1<A[i].A.size();k1++) next.push_back(A[i].A[k1]); 
                if (solvel(A[i].u)&&solver(A[i].v)){
                    len++; B[len].u=Q.front(); B[len].v=Q.back(); B[len].len=Q.size()-1;
                }
            }
    for (int i=1;i<=m;i++){
        if (A[i].A.size()==0||A[i].A[0]!=A[i].v) continue;
        Q.clear(); next.clear();
        for (int k1=1;k1<A[i].A.size();k1++) next.push_back(A[i].A[k1]); 
        if (solver(A[i].v)){
            now++; C[now].u=A[i].u; C[now].v=Q.back(); C[now].len=Q.size();
        }
    }
    for (int i=1;i<=m;i++){
        if (A[i].A.size()==0||A[i].A[(A[i].A.size())-1]!=A[i].u) continue; 
        Q.clear(); next.clear();
        for (int k1=(A[i].A.size())-2;k1>=0;k1--) next.push_back(A[i].A[k1]); 
        if (solver2(A[i].u)){
            now2++; D[now2].v=A[i].v; D[now2].u=Q.back(); D[now2].len=Q.size();
        }
    }
    for (int i=1;i<=len;i++) f[B[i].len][B[i].u][B[i].v]++;
/*  cout<<"B"<<endl;
    for (int i=1;i<=len;i++) cout<<B[i].u<<" "<<B[i].v<<" "<<B[i].len<<endl;
    cout<<"C"<<endl;
    for (int i=1;i<=now;i++) cout<<C[i].u<<" "<<C[i].v<<" "<<C[i].len<<endl;
    cout<<"D"<<endl;
    for (int i=1;i<=now2;i++) cout<<D[i].u<<" "<<D[i].v<<" "<<D[i].len<<endl;
    cout<<now<<endl;*/
    for (int i=1;i<=n*2;i++)
        for (int j=1;j<=now;j++)
            if (C[j].len<=i)
                for (int k=1;k<=n;k++)
                    f[i][k][C[j].v]=(f[i][k][C[j].v]+f[i-C[j].len][k][C[j].u])%mo;
/*  for (int i=1;i<=n*2;i++)
        for (int j=1;j<=n;j++)
            for (int k=1;k<=n;k++)
                if (f[i][j][k]) cout<<i<<" "<<j<<" "<<k<<endl;*/
    for (int i=1;i<=n*2;i++)
        for (int j=1;j<=now2;j++)
            if (D[j].len<=i)
                for (int k=1;k<=n;k++)
                    f[i][D[j].u][k]=(f[i][D[j].u][k]+f[i-D[j].len][D[j].v][k])%mo;
    for (int i=1;i<=n*2;i++)
        for (int j=1;j<=m;j++)
            if (A[j].A.size()==0)
                for (int k=1;k<=n;k++) w[i][A[j].u][k]=(w[i][A[j].u][k]+f[i-1][A[j].v][k])%mo;
    for (int i=1;i<=n*2;i++)
        for (int j=1;j<=n;j++)
            for (int k=1;k<=n;k++) g[i][k]=(g[i][k]+f[i][j][k])%mo;
    for (int i=1;i<=n*2;i++)
        for (int k1=1;k1<i;k1++)
            for (int k2=1;k2<=n;k2++)
                for (int k=1;k<=n;k++)
                    g[i][k]=(1ll*g[k1][k2]*w[i-k1][k2][k]+g[i][k])%mo;
    for (int i=1;i<=n*2;i++){
        int ans=0;
        for (int j=1;j<=n;j++) ans=(ans+g[i][j])%mo; cout<<ans<<endl;
    }
    return 0;
}