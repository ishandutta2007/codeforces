#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
struct atom{
    int w;
    long long where;
    void scan(){
        scanf("%I64d%d",&where,&w);
    }
}A[200000];
int pd[200000],n,m,k,b[200000],bo[200000],B[200000];
long long h,d[20000];
vector<int>x[20000];
int compare(int k1,int k2){
    return A[k1].where<A[k2].where;
}
int operator < (atom k1,atom k2){
    return k1.w<k2.w||(k1.w==k2.w&&k1.where>k2.where);
}
priority_queue<atom>Q;
queue<int>S;
void change(long long now){
    for (int i=0;i<k;i++) {pd[i]=1; S.push(i);}
    while (!S.empty()){
        int k1=S.front(),k2=(k1+now)%k;
        if (d[k2]>d[k1]+now){
            d[k2]=d[k1]+now;
            if (pd[k2]==0){
                pd[k2]=1; S.push(k2); 
            }
        }
        pd[k1]=0; S.pop();
    }
    for (int i=0;i<=k;i++){
        int k1=x[i].size()-1; 
        while (k1>=0&&A[x[i][k1]].where>=d[i]){Q.push((atom){A[x[i][k1]].w,x[i][k1]}); bo[x[i][k1]]=1; x[i].pop_back(); k1--;}
    }
}
int main(){
    scanf("%I64d%d%d%d",&h,&n,&m,&k);
    memset(d,0x3f,sizeof d); d[1]=1;
    for (int i=1;i<=n;i++) A[i].scan();
    for (int i=1;i<=n;i++) b[i]=i; sort(b+1,b+n+1,compare);
    for (int i=1;i<=n;i++) x[A[b[i]].where%k].push_back(b[i]);
    change(k); memset(pd,0x00,sizeof pd);
//  for (int i=1;i<=n;i++) cout<<pd[i]<<" "<<B[i]<<endl;
    for (;m;m--){
        int k1,k2,k3; scanf("%d",&k1);
        if (k1==1){
            long long k4; scanf("%I64d",&k4); change(k4);
        } else if (k1==2){
            scanf("%d%d",&k2,&k3); A[k2].w-=k3; 
            if (B[k2]==0&&bo[k2]) Q.push((atom){A[k2].w,k2});
        } else if (k1==3){
            while (!Q.empty()&&(Q.top().w!=A[Q.top().where].w||B[Q.top().where])) Q.pop();
            if (Q.empty()){printf("0\n"); continue;}
            int kk=Q.top().where; printf("%d\n",A[kk].w); Q.pop();
            B[kk]=1; bo[kk]=0;
        }
    }
    return 0;
}