#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;
int n;
int bit[100005];
inline void upd(int x,int del){for(;x<=n;x+=x&-x)bit[x]+=del;}
inline int que(int x){int ans=0;for(;x;x-=x&-x)ans+=bit[x];return ans;}
inline int q1(int x){return que(x)-que(x-1);}
int l,r;
int main()
{
    int q;
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++)upd(i,1);
    l=0,r=n;
    while(q--){
               int opt;scanf("%d",&opt);
               if(opt==1){
                          int x;scanf("%d",&x);
                          if(l<r){
                                   int llen=x,rlen=r-l-x;
                                   if(llen<=rlen){
                                                  for (int i=l+x;i>l;i--){
                                                      int t=q1(i);
                                                      upd(2*(l+x)-i+1,t);
                                                      upd(i,-t);
                                                  }
                                                  l=l+x;
                                   }else{
                                         for (int i=l+x+1;i<=r;i++){
                                             int t=q1(i);
                                             upd(2*(l+x)-i+1,t);
                                             upd(i,-t);
                                         }
                                         r=l;l=l+x;
                                   }                             
                          }else if(l>r){
                                   int llen=x,rlen=l-r-x;
                                   if(llen<=rlen){
                                                  for (int i=l-x+1;i<=l;i++){
                                                      int t=q1(i);
                                                      upd(2*(l-x)-i+1,t);
                                                      upd(i,-t);
                                                  }
                                                  l=l-x;
                                   }else{
                                         for (int i=l-x;i>r;i--){
                                             int t=q1(i);
                                             upd(2*(l-x)-i+1,t);
                                             upd(i,-t);
                                         }
                                         r=l;l=l-x;
                                   }
                          }
               }else{
                     int L,R;scanf("%d%d",&L,&R);
                     if(l<r){
                            printf("%d\n",que(l+R)-que(l+L));
                     }else{
                           printf("%d\n",que(l-L)-que(l-R));
                     }
               }
    }
    return 0;
}