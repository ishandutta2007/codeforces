#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct atom{
    int where,w;
};
int operator < (const atom k1,const atom k2){
    return k1.w<k2.w;
}
priority_queue<atom>Q;
int x[200],y[200],n,d,a[200],pd[200],dd[200];
int dis(int k1,int k2){
    return abs(x[k1]-x[k2])+abs(y[k1]-y[k2]);
}
int check(int k){
    while (!Q.empty()) Q.pop();
    memset(dd,0xff,sizeof dd); dd[1]=k; Q.push((atom){1,k});
    memset(pd,0x00,sizeof pd);
    while (!Q.empty()){
        while (!Q.empty()&&pd[Q.top().where]) Q.pop(); if (Q.empty()) return 0;
        int k1=Q.top().where; pd[k1]=1; if (k1==n) return 1; Q.pop();
        for (int i=1;i<=n;i++)
            if (pd[i]==0){
                int k2=dd[k1]+a[k1]-dis(k1,i)*d;
                if (k2>dd[i]&&k2>=0){
                    dd[i]=k2; Q.push((atom){i,k2});
                }
            }
    }
    return 0;
}
int main(){
    scanf("%d%d",&n,&d);
    for (int i=2;i<n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
    int l=0,r=dis(1,n)*d+1,ans;
    while (l<r){
        int mid=l+r>>1;
        if (check(mid)){ans=mid; r=mid;} else l=mid+1;
    }
    cout<<ans<<endl; return 0;
}