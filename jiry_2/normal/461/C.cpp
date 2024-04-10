#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
struct atom{
    int l,r,w;
}x[110000],y[110000],z[110000];
int n,q,len;
void fold(int k){
    if (k==1) return;
    int now=len+1;
    for (int i=1;i<=len;i++) if (x[i].r>=k){now=i; break;}
    int len1=0,len2=0;
    for (int i=1;i<=now-1;i++){len1++; y[len1]=x[i];}
    if (x[now].l!=k&&now!=len+1){len1++; y[len1]=(atom){x[now].l,k-1,x[now].w};}
    if (now!=len+1){len2=1; z[1]=(atom){k,x[now].r,x[now].w};}
    for (int i=now+1;i<=len;i++){len2++; z[len2]=x[i];}
//  cout<<"y"<<endl;
//  for (int i=1;i<=len1;i++) cout<<y[i].l<<" "<<y[i].r<<" "<<y[i].w<<endl;
//  cout<<"z"<<endl;
//  for (int i=1;i<=len2;i++) cout<<z[i].l<<" "<<z[i].r<<" "<<z[i].w<<endl;
    for (int i=1;i<=len1;i++){y[i].l=k-y[i].l; y[i].r=k-y[i].r; swap(y[i].l,y[i].r);}
    for (int i=1;i<=len2;i++){z[i].l=z[i].l-k+1; z[i].r=z[i].r-k+1;}
    len=0; int k1=len1,k2=1; x[0].r=0; y[0].w=0; z[len2+1].w=0;
//  cout<<"y"<<endl;
//  for (int i=1;i<=len1;i++) cout<<y[i].l<<" "<<y[i].r<<" "<<y[i].w<<endl;
//  cout<<"z"<<endl;
//  for (int i=1;i<=len2;i++) cout<<z[i].l<<" "<<z[i].r<<" "<<z[i].w<<endl;
    while (k1||k2<=len2){
        if (k1&&y[k1].r==x[len].r) k1--;
        if (k2<=len2&&z[k2].r==x[len].r) k2++;
        if (k1==0&&k2>len2) break;
        if ((y[k1].r<z[k2].r&&k1>0)||k2>len2){
            len++; x[len].l=x[len-1].r+1; x[len].r=y[k1].r; x[len].w=y[k1].w+z[k2].w; k1--;
        } else {
            len++; x[len].l=x[len-1].r+1; x[len].r=z[k2].r; x[len].w=y[k1].w+z[k2].w; k2++;
        }
    }
}
int find(int k){
    if (k==0) return 0;
    int now=1,ans=0;
    for (;now<=len;now++){
        if (x[now].r>=k) break;
        ans+=x[now].w*(x[now].r-x[now].l+1);
    }
//  cout<<now<<" "<<k<<endl;
    ans+=x[now].w*(k-x[now].l+1); return ans;
}
int main(){
    scanf("%d%d",&n,&q);
    len=1; x[1]=(atom){1,n,1}; x[2].l=n+100;
    for (;q;q--){
    //  cout<<"x"<<endl;
    //  for (int i=1;i<=len;i++) cout<<x[i].l<<" "<<x[i].r<<" "<<x[i].w<<endl;
        int k1,k2; scanf("%d",&k1);
        if (k1==1){
            scanf("%d",&k2); k2++; fold(k2);
        } else if (k1==2){
            scanf("%d%d",&k1,&k2); printf("%d\n",find(k2)-find(k1));
        }
    }
    return 0;
}