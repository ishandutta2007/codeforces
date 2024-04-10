#include<iostream>
#include<cmath> 
#include<cstdio>
#include<cstring> 
#include<algorithm>

#define rep(i,j,k) for(i=j;i<=k;i++)
#define rrep(i,j,k) for(i=j;i>=k;i--)
#define INF 0x3f3f3f3f

using namespace std;

int i,j,n,a[20][20];

int main(){
    cin>>n;
    rep(i,1,n){
        a[i][1]=1;
        a[1][i]=1;
    } 
    rep(i,2,n)
    rep(j,2,n)
        a[i][j]=a[i-1][j]+a[i][j-1];
    cout<<a[n][n]<<endl;
    return 0;
}