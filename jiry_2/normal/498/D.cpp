#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,a[110000],m,num[610000][61];
void update(int k1){
    for (int i=0;i<60;i++) num[k1][i]=num[k1*2][i]+num[k1*2+1][(i+num[k1*2][i])%60];
}
void buildtree(int k1,int k2,int k3){
    if (k2==k3){
        for (int i=0;i<60;i++) if (i%a[k2]==0) num[k1][i]=2; else num[k1][i]=1; return;
    }
    int mid=k2+k3>>1;
    buildtree(k1*2,k2,mid); buildtree(k1*2+1,mid+1,k3); update(k1);
}
void change(int k1,int k2,int k3,int k4){
    if (k2==k3){
        for (int i=0;i<60;i++) if (i%a[k2]==0) num[k1][i]=2; else num[k1][i]=1; return;
    }
    int mid=k2+k3>>1;
    if (mid>=k4) change(k1*2,k2,mid,k4); else change(k1*2+1,mid+1,k3,k4);
    update(k1);
}
int find(int k1,int k2,int k3,int k4,int k5,int k6){
    if (k2>k5||k3<k4) return 0;
    if (k2>=k4&&k3<=k5) return num[k1][k6];
    int mid=k2+k3>>1; int k7=find(k1*2,k2,mid,k4,k5,k6);
    return k7+find(k1*2+1,mid+1,k3,k4,k5,(k6+k7)%60);
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    buildtree(1,1,n); scanf("%d",&m);
    for (;m;m--){
        char ch[10]; scanf("%s",ch);
        if (ch[0]=='A'){
            int k1,k2; scanf("%d%d",&k1,&k2); if (k1==k2) printf("0\n"); else printf("%d\n",find(1,1,n,k1,k2-1,0));
        } else {
            int k1,k2; scanf("%d%d",&k1,&k2); a[k1]=k2; change(1,1,n,k1);
        }
    }
    return 0;
}