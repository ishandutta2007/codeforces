#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
int where[20],pre[20],A[1100000],B[2100000],n,m,pd[110000],len,h[110000],lim,d[110000];
priority_queue<int,vector<int>,greater<int> >S;
void change(int *num,int k1,int k2,int k3,int k4,int k5){
    if (k2==k3){num[k1]=k5; return;}
    int mid=k2+k3>>1;
    if (mid>=k4) change(num,k1*2,k2,mid,k4,k5); else change(num,k1*2+1,mid+1,k3,k4,k5);
    num[k1]=max(num[k1*2],num[k1*2+1]);
}
int find(int *num,int k1,int k2,int k3,int k4,int k5){
//  if (k4==210) cout<<"find "<<k1<<" "<<k2<<" "<<k3<<" "<<k4<<" "<<k5<<" "<<num[k1]<<endl;
    if (k2>k5||k3<k4) return 0;
    if (k2>=k4&&k3<=k5) return num[k1];
    int mid=k2+k3>>1;
    return max(find(num,k1*2,k2,mid,k4,k5),find(num,k1*2+1,mid+1,k3,k4,k5));
}
void changeB(){
    for (int i=1;i<=10;i++) if (pd[where[i]]==0&&where[i]>pre[len]) change(B,1,1,lim,h[where[i]],d[where[i]]);
    for (int i=1;i<=len;i++) d[pre[i]]=find(B,1,1,lim,h[pre[i]]+1,lim)+1;
//  for (int i=1;i<=10;i++) cout<<pre[i]<<" "; cout<<endl;
//  for (int i=1;i<=10;i++) cout<<d[pre[i]]<<" "; cout<<endl;
//  for (int i=1;i<=10;i++) cout<<h[pre[i]]-m<<" "; cout<<endl; cout<<"asdasd"<<endl;
    for (int i=len;i;i--)
        for (int j=i+1;j<=len;j++)
            if (h[pre[i]]<h[pre[j]])
                d[pre[i]]=max(d[pre[i]],d[pre[j]]+1);
}
int main(){
    scanf("%d%d",&n,&m); pd[0]=1; len=0; lim=m+20;
    for (;m;m--){
        int k1,k2; scanf("%d",&k1);
        if (pd[where[10]]==0) change(A,1,1,n,where[10],d[where[10]]);
        for (int i=10;i;i--) where[i]=where[i-1]; //cout<<where[0]<<endl;
        if (k1==1){
            scanf("%d%d",&k1,&k2); where[k2]=k1; h[k1]=k2+m; d[k1]=1; 
            d[k1]=find(A,1,1,n,k1+1,n)+1; 
            for (int i=10;i;i--)
                for (int j=i+1;j<=10;j++)
                    if (pd[where[i]]==0&&pd[where[j]]==0&&where[i]<where[j])d[where[i]]=max(d[where[i]],d[where[j]]+1);
//          for (int i=1;i<=10;i++) cout<<where[i]<<" "; cout<<endl;
//          for (int i=1;i<=10;i++) cout<<d[where[i]]<<" "; cout<<endl;
            if (k1>pre[len]){
                if (len==10){change(B,1,1,lim,h[k1],d[k1]); S.push(k1);} else pre[++len]=k1;
            } else {
                int k3,k4;
                for (int i=1;i<=len;i++) if (pre[i]>k1) {k3=i; break;}
                k4=pre[len];
                for (int i=len;i>k3;i--) pre[i]=pre[i-1]; pre[k3]=k1;
                if (len==10) {change(B,1,1,lim,h[k4],d[k4]); S.push(k4);} else pre[++len]=k4;
            }
            changeB(); 
        } else {
            scanf("%d",&k1); k2=k1; k1=pre[k1]; pd[k1]=1;
            change(A,1,1,n,k1,0); 
            for (int i=k2;i<len;i++) pre[i]=pre[i+1]; 
            while (!S.empty()&&pd[S.top()]) S.pop();
            if (S.empty()) len--; else {
                int k2=S.top(); S.pop(); pre[len]=k2; change(B,1,1,lim,h[k2],0);
            }
            for (int i=1;i<=10;i++) if (pd[where[i]]==0) change(B,1,1,lim,h[where[i]],0);
            for (int i=1;i<=len;i++) change(A,1,1,n,pre[i],0);
            for (int i=1;i<=10;i++) if (pd[where[i]]==0) d[where[i]]=find(A,1,1,n,where[i]+1,n)+1;
            for (int i=1;i<=len;i++) d[pre[i]]=find(B,1,1,lim,h[pre[i]]+1,lim)+1;
            for (int i=len;i;i--)
                for (int j=i+1;j<=len;j++)
                    if (h[pre[i]]<h[pre[j]]) d[pre[i]]=max(d[pre[i]],d[pre[j]]+1);
            for (int i=10;i;i--)
                for (int j=i+1;j<=10;j++)
                    if (pd[where[i]]==0&&pd[where[j]]==0&&where[i]<where[j]) d[where[i]]=max(d[where[i]],d[where[j]]+1);
            for (int i=1;i<=10;i++) if (pd[where[i]]==0&&where[i]>pre[len]) change(B,1,1,lim,h[where[i]],d[where[i]]);
            for (int i=1;i<=len;i++) if (h[pre[i]]-m>10) change(A,1,1,n,pre[i],d[pre[i]]);
        }
        int ans=A[1]; for (int i=1;i<=10;i++) if (pd[where[i]]==0) ans=max(ans,d[where[i]]);
//      for (int i=1;i<=n;i++) if (d[i]) cout<<i<<" "<<h[i]-m<<" "<<h[i]<<" "<<d[i]<<endl;
//      for (int i=1;i<=10;i++) cout<<where[i]<<" "; cout<<endl;
//      for (int i=1;i<=10;i++) cout<<d[where[i]]<<" "; cout<<endl;
        printf("%d\n",ans);
    }
    return 0;
}