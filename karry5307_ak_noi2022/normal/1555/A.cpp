#include<bits/stdc++.h>
using namespace std;
int T;
long long n;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%lld",&n);
        if(n&1) n++;
        printf("%lld\n",max(n,6ll)/2*5);
    }
    return 0;
}