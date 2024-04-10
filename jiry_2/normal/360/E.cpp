#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
struct atom{
    int l,r,u,v,where,pd;
}A[200];
struct bian{
    int next,point,w;
}b[20000];
int n,m,k,len,p[20000],s1,s2,f,pd[20000];
long long d1[20000],d2[20000];
queue<int>Q;
void add(int k1,int k2,int k3){
    b[++len]=(bian){p[k1],k2,k3}; p[k1]=len;
}
void getd1(int s,int t){
    memset(pd,0x00,sizeof pd);
    memset(d1,0x3f,sizeof d1); d1[s]=0; pd[s]=1; Q.push(s);
    while (!Q.empty()){
        int k=Q.front(); 
        for (int i=p[k];i;i=b[i].next){
            int j=b[i].point;
            if (d1[k]+b[i].w<d1[j]){
                d1[j]=d1[k]+b[i].w;
                if (pd[j]==0){
                    Q.push(j); pd[j]=1;
                }
            }
        }
        pd[k]=0; Q.pop();
    }
}
void getd2(int s,int t){
    memset(pd,0x00,sizeof pd);
    memset(d2,0x3f,sizeof d2); d2[s]=0; pd[s]=1; Q.push(s);
    while (!Q.empty()){
        int k=Q.front(); 
        for (int i=p[k];i;i=b[i].next){
            int j=b[i].point;
            if (d2[k]+b[i].w<d2[j]){
                d2[j]=d2[k]+b[i].w;
                if (pd[j]==0){
                    Q.push(j); pd[j]=1;
                }
            }
        }
        pd[k]=0; Q.pop();
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    scanf("%d%d%d",&s1,&s2,&f);
    for (int i=1;i<=m;i++){
        int k1,k2,k3; scanf("%d%d%d",&k1,&k2,&k3); add(k1,k2,k3);
    }
    for (int i=1;i<=k;i++){
        scanf("%d%d%d%d",&A[i].u,&A[i].v,&A[i].l,&A[i].r);
        A[i].where=len+1; add(A[i].u,A[i].v,A[i].r);
    }
    getd1(s1,f); getd2(s2,f);
//  for (int i=1;i<=len;i++) cout<<b[i].w<<" "; cout<<endl;
    while (1){
        int now=0;
//      for (int i=1;i<=n;i++) cout<<d1[i]<<" "; cout<<endl;
//      for (int i=1;i<=n;i++) cout<<d2[i]<<" "; cout<<endl;
//      cout<<endl;
        for (int i=1;i<=k;i++) if (A[i].pd==0&&d1[A[i].u]<d2[A[i].u]){now=i; break;}
        if (now==0) break;
        A[now].pd=1; b[A[now].where].w=A[now].l;
        getd1(s1,f); getd2(s2,f);
    }
    if (d1[f]<d2[f]){
        cout<<"WIN"<<endl;
        for (int i=1;i<=k;i++) if (A[i].pd==0) cout<<A[i].r<<" "; else cout<<A[i].l<<" "; cout<<endl; return 0;
    }
    while (1){
        int now=0;
        for (int i=1;i<=k;i++) if (A[i].pd==0&&d1[A[i].u]<=d2[A[i].u]){now=i; break;}
        if (now==0) break;
        A[now].pd=1; b[A[now].where].w=A[now].l;
        getd1(s1,f); getd2(s2,f);
    }
    if (d1[f]<=d2[f]){
        cout<<"DRAW"<<endl;
        for (int i=1;i<=k;i++) if (A[i].pd==0) cout<<A[i].r<<" "; else cout<<A[i].l<<" "; cout<<endl; return 0;
    }
    cout<<"LOSE"<<endl; return 0;
}