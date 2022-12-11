#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int w[210000],n,m,p[210000],A[210000],B[210000],lim=314000000,aim[210000],c[210000],pd[210000],e[210000];
vector<int>b[210000],x[210000],d[210000];
struct atom{
    int w,where;
};
int operator < (const atom k1,const atom k2){
    return k1.w>k2.w;
}
priority_queue<atom>Q;
int update(int k1,int k2){
    if (A[k1]==-1||A[k1]>k2) {A[k1]=k2; return 1;} else return 0;
}
int dfs(int k){
    if (pd[k]){B[k]=-2; return -2;}
    if (B[k]!=0) return B[k]; pd[k]=1;
    for (int i=0;i<x[k].size();i++){
        int j=x[k][i]; if (c[j]) continue; int num=e[j];
        for (int k1=0;k1<d[j].size();k1++){
            int k2=dfs(d[j][k1]); if (k2==-2){pd[k]=0; B[k]=-2; return -2;}
            num=min(num+k2,lim); 
        }
        B[k]=max(B[k],num);
    }
    pd[k]=0; return B[k];
}
int main(){
    scanf("%d%d",&m,&n);
    for (int i=1;i<=m;i++){
        int k1; scanf("%d",&k1); x[k1].push_back(i); aim[i]=k1; scanf("%d",&k1);
        for (;k1;k1--){
            int k2; scanf("%d",&k2); if (k2==-1) w[i]++; else {c[i]++; b[k2].push_back(i); d[i].push_back(k2);}
        }
    }
    memset(A,0xff,sizeof A); memcpy(e,w,sizeof w);
    for (int i=1;i<=m;i++) if (c[i]==0&&update(aim[i],w[i])) Q.push((atom){A[aim[i]],aim[i]});
    while (!Q.empty()){
        int k=Q.top().where; if (pd[k]){Q.pop(); continue;} pd[k]=1;
        for (int i=0;i<b[k].size();i++){
            int j=b[k][i]; w[j]=min(w[j]+A[k],lim); c[j]--;
            if (c[j]==0){
                if (update(aim[j],w[j])) Q.push((atom){A[aim[j]],aim[j]});
            }
        }
        Q.pop();
    }
    memset(pd,0x00,sizeof pd); memset(B,0x00,sizeof B); memset(c,0x00,sizeof c);
    for (int i=1;i<=n;i++) if (A[i]==-1) for (int j=0;j<b[i].size();j++) c[b[i][j]]=1;
    for (int i=1;i<=n;i++) if (A[i]>=0) dfs(i); else B[i]=-1;
    for (int i=1;i<=n;i++) printf("%d %d\n",A[i],B[i]);
    return 0;
}