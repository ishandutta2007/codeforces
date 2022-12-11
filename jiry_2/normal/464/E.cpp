#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct tree{
    int l,r,w,pre;
}t[3650000];
int len,n,m,lim=100020,x[110000],mo=1e9+7,d[110000],s,T,two[110000];
void update(int k1,int k2,int k3){
    int mid=k2+k3>>1;
    t[k1].w=(1ll*t[t[k1].r].w*two[mid-k2+1]%mo+t[t[k1].l].w)%mo;
    if (t[k1].r==0) t[k1].pre=k3; else if (t[t[k1].r].pre) t[k1].pre=t[t[k1].r].pre; else if (t[k1].l==0) t[k1].pre=mid; else t[k1].pre=t[t[k1].l].pre;
}
int addin(int k1,int k2,int k3,int k4){
    t[++len]=t[k1]; if (k2==k3){t[len].pre=0; t[len].w=1; return len;} int now=len;
    int mid=k2+k3>>1; if (mid>=k4) t[now].l=addin(t[k1].l,k2,mid,k4); else t[now].r=addin(t[k1].r,mid+1,k3,k4);
    update(now,k2,k3); //cout<<k1<<" "<<k2<<" "<<k3<<" "<<k4<<" "<<t[now].w<<endl; 
    return now;
}
int addin0(int k1,int k2,int k3,int k4,int k5){
    if (k2>k5||k3<k4) return k1;
    t[++len]=t[k1]; int now=len,mid=k2+k3>>1;
    if (k2>=k4&&k3<=k5){t[now].w=0; t[now].pre=k3; t[now].l=0; t[now].r=0; return now;}
    t[now].l=addin0(t[k1].l,k2,mid,k4,k5); t[now].r=addin0(t[k1].r,mid+1,k3,k4,k5); 
    update(now,k2,k3); return now;
}
int findpre(int k1,int k2,int k3,int k4){
    //cout<<k1<<" "<<k2<<" "<<k3<<" "<<k4<<" "<<t[k1].l<<" "<<t[t[k1].l].pre<<endl;
    if (k1==0) return max(k4,k2);  if (t[k1].pre<k4) return 0;
    if (k2==k3) return k2; int mid=k2+k3>>1;
    if (mid<k4) return findpre(t[k1].r,mid+1,k3,k4);
    if (t[k1].l==0||t[t[k1].l].pre>=k4) return findpre(t[k1].l,k2,mid,k4);
    return findpre(t[k1].r,mid+1,k3,k4);
}
int find(int k1,int k2,int k3,int k4){
    if (k3==k4) return t[k1].w>t[k2].w;
    int mid=k3+k4>>1;
    if (t[t[k1].r].w==t[t[k2].r].w) return find(t[k1].l,t[k2].l,k3,mid);
    return find(t[k1].r,t[k2].r,mid+1,k4);
}
struct atom{
    int root,where,pre;
};
int operator < (const atom k1,const atom k2){
    return find(k1.root,k2.root,1,lim);
}
int insert(int k1,int k2){
    k2++; int k3=findpre(d[k1],1,lim,k2);// cout<<"addin "<<k1<<" "<<k2<<" "<<k3<<endl; 
    int k5=addin(addin0(d[k1],1,lim,k2,k3-1),1,lim,k3); return k5;
}
priority_queue<atom>Q;
struct bian{
    int next,point,w;
}b[210000];
int p[110000],pd[110000],go[110000];
void ade(int k1,int k2,int k3){
    b[++len]=(bian){p[k1],k2,k3}; p[k1]=len;
}
void add(int k1,int k2,int k3){
    ade(k1,k2,k3); ade(k2,k1,k3);
}
int main(){
    scanf("%d%d",&n,&m); len=0; memset(p,0x00,sizeof p);
    two[0]=1; for (int i=1;i<=100020;i++) two[i]=two[i-1]*2%mo;
    for (int i=1;i<=m;i++){int k1,k2,k3; scanf("%d%d%d",&k1,&k2,&k3); add(k1,k2,k3);} scanf("%d%d",&s,&T);
    memset(d,0xff,sizeof d); len=0; d[s]=0; Q.push((atom){0,s,0}); memset(go,0xff,sizeof go);
    while (!Q.empty()){
        while (!Q.empty()&&pd[Q.top().where]) Q.pop(); //cout<<"add "<<Q.top().where<<" "<<t[d[Q.top().where]].w<<" "<<d[Q.top().where]<<endl; 
        if (Q.empty()) break; int k=Q.top().where; pd[k]=1; go[k]=Q.top().pre;
        for (int i=p[k];i;i=b[i].next){
            int j=b[i].point; if (pd[j]==1) continue; int now=insert(k,b[i].w); 
            if (d[j]==-1||find(d[j],now,1,lim)){d[j]=now; atom k1=(atom){d[j],j,k}; Q.push(k1);}
        }
    }
    if (go[T]==-1){cout<<-1<<endl; return 0;}
    cout<<t[d[T]].w<<endl; int ans=0;
    for (int i=T;i;i=go[i]) x[++ans]=i; cout<<ans<<endl;
    for (int i=ans;i;i--) printf("%d ",x[i]); cout<<endl; return 0;
}