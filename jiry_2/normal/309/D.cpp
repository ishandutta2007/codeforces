#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m;
int main(){
    scanf("%d%d",&n,&m); n++; long long ans=0;
    for (int i=m+1;i<=n-m-1;i++){
        int k=n-m-1;
        int pre=1ll*2*i*i+n*n+i*(n-m)-3*i*n-(n-m)*n-(n-m-i-n)*k;
        for (int j=n-m-1;j>=m+1&&k>m;j--){
            pre+=n+k-i;
            while (k>m&&pre>=0) {k--; pre+=j-i-n;}
            ans+=k-m;
        }
    }
    cout<<ans*3<<endl; return 0;
}