// Hydro submission #61ab7042ec57f02a8c24e99c@1638625347066
//hydro CF1161B chenyilai
#include<bits/stdc++.h>
using namespace std;
long long T,a,b,x;
int main(){
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld",&a,&b);
        if(a>b){
            if(a>=3*b)printf("%lld\n",b);
            else{
                x=(a-b)/2;
                printf("%lld\n",x+(b-x)/2);
            }
        }
        else{
            if(b>=3*a)printf("%lld\n",a);
            else{
                x=(b-a)/2;
                printf("%lld\n",x+(a-x)/2);
            }
        }
    }
    return 0;
}