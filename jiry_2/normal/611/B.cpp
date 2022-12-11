#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    long long l,r; scanf("%I64d%I64d",&l,&r);
    int ans=0;
    for (int i=2;i<=61;i++)
        for (int j=1;j<i;j++){
            long long now=(1ll<<i)-(1ll<<(j-1))-1;
            if (now>=l&&now<=r) ans++;
        }
    cout<<ans<<endl;
    return 0;
}