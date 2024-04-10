#include<iostream>
#include<cmath> 
#include<cstdio>
#include<cstring> 
#include<algorithm>

#define rep(i,j,k) for(i=j;i<=k;i++)
#define rrep(i,j,k) for(i=j;i>=k;i--)
#define INF 0x3f3f3f3f

using namespace std;

int i,j,n,m;
char a[60][60];

int main(){
    cin>>n>>m;
    rep(i,1,n)
    rep(j,1,m)
        if (i%2==1)
            a[i][j]='#';
        else
            a[i][j]='.';
    rep(i,1,n)
         if (i%2==0){
            if (i%4==2)
                a[i][m]='#';
            else
                a[i][1]='#';
         }
    rep(i,1,n){
        rep(j,1,m)
            printf("%c",a[i][j]);
        cout<<endl;
    }
    return 0;
}