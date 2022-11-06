#include<bits/stdc++.h>
using namespace std;
int n,m=100000007,d;
int main(){
    scanf("%d",&n);
    for(int i=n;i;i--){
        int v=i+(n-1)/i+1;
        if(v<m)m=v,d=i;
    }//printf("%d",d);
    for(int i=n;0<i;i-=d){
        for(int j=max(1,i-d+1);j<=i;j++)printf("%d ",j);
    }
    return 0;
}