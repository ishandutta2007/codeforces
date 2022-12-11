#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int A[50][50],n,w[2]={1,-1},b[50];
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) scanf("%d",&A[i][j]);
    int x=(n+1)/2,ans=0;
    for (int i=0;i<(1<<x);i++){
        int num=0;
        for (int j=1;j<=x;j++) b[j]=((i&(1<<j-1))>0);
        for (int j=1;j<x;j++) b[j+x]=(b[j]^b[x]);
        for (int j=1;j<=n;j++) num+=w[b[j]]*A[j][x];
        for (int j=1;j<x;j++){
            int now=0;
            for (int k1=0;k1<=1;k1++){
                int k2=k1^b[x]; int noww=w[k1]*A[x][j]+w[k2]*A[x][j+x];
                for (int k=1;k<x;k++){
                    int k3=A[k][j]*w[0]+A[k+x][j]*w[k1]+A[k][j+x]*w[b[k]]+A[k+x][j+x]*w[b[k]^k2];
                    int k4=A[k][j]*w[1]+A[k+x][j]*w[k1^1]+A[k][j+x]*w[b[k]^1]+A[k+x][j+x]*w[b[k]^k2^1];
                    noww+=max(k3,k4);
                }
                now=max(now,noww);
            }
            num+=now;
        }
        ans=max(ans,num);
    }
    cout<<ans<<endl; return 0;
}