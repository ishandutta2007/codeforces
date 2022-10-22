#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=3e5+10;
int main(){
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n/2;i++){
        for(j=1;j<=m;j++){
            printf("%d %d\n%d %d\n",i,j,n+1-i,m+1-j);
        }
    }
    if(n%2){
        for(j=1;j<=m/2;j++)printf("%d %d\n%d %d\n",n/2+1,j,n/2+1,m+1-j);
        if(m%2)printf("%d %d\n",n/2+1,m/2+1);
    }
}