// remote judge
#include<bits/stdc++.h>
using namespace std;
bool check(int a){
    int sum=0;
    for(;a;a/=10){
        sum+=a%10;
    }
    return sum%4==0;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("CF1183A.in","r",stdin);
    freopen("CF1183A.out","w",stdout);
#endif
    int a;
    scanf("%d",&a);
    for(;!check(a);++a);
    printf("%d\n",a);
    return 0;
}