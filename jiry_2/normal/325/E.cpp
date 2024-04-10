#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,pd[100100],next[100100];
int dfs(int k1,int k2){
    if (pd[k1]==1){
        if (k1==0&&k2==n) return 1; return 0;
    }
    pd[k1]=1;
    if (pd[(k1+n/2)%n]){
        int k3; if (next[(k1+n/2)%n]==2*k1%n) k3=(2*k1+1)%n; else k3=2*k1%n;
        next[k1]=k3; if (dfs(k3,k2+1)) return 1;
    } else {
        next[k1]=k1*2%n; if (dfs(k1*2%n,k2+1)) return 1;
        if (pd[(k1+n/2)%n]==0){
            next[k1]=(k1*2+1)%n; if (dfs(next[k1],k2+1)) return 1;
        }
    }
    return 0;
}
int main(){
    scanf("%d",&n); if (n%2==1){cout<<-1<<endl; return 0;}
    memset(pd,0x00,sizeof pd); dfs(0,0); //cout<<next[0]<<" "<<next[1]<<endl;
    printf("0 "); for (int i=next[0];i;i=next[i]) printf("%d ",i); cout<<0<<endl; return 0;
}