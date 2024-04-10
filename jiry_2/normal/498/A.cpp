#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,xx1,xx2,yy1,yy2,a,b,c;
int main(){
    scanf("%d%d%d%d",&xx1,&yy1,&xx2,&yy2);
    scanf("%d",&n); int ans=0;
    for (;n;n--){
        scanf("%d%d%d",&a,&b,&c);
        long long k1=1ll*a*xx1+1ll*b*yy1+c;
        long long k2=1ll*a*xx2+1ll*b*yy2+c;
        if (k1>0&&k2<0) ans++; else if (k1<0&&k2>0) ans++;
    }
    cout<<ans<<endl; return 0;
}