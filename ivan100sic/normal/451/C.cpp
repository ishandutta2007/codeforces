#include <cstdio>
#include <cstring>
#include <algorithm>
//#define STRING "%I64d"
using namespace std;

long long T,N,K,d1,d2,a,b,c,p1,p2,dd1,dd2;

int main(){
    scanf("%lld",&T);
    while (T--){
        scanf("%lld%lld%lld%lld",&N,&K,&d1,&d2);
        if (N%3 != 0){
            printf("no\n");
            continue;
        }
        for (p1=-1; p1<=1; p1+=2){
            for (p2=-1; p2<=1; p2+=2){
                dd1 = d1*p1;
                dd2 = d2*p2;
                //a-b = d1 , b-c = d2 , a+b+c = k
                //a-2b+c = d1-d2
                //-3b = d1-d2-k
                //b = (k+d2-d1)/3
                b = (K+dd2-dd1)/3;
                a = b+dd1;
                c = b-dd2;
                //printf("d: %lld %lld v: %lld %lld %lld mod = %lld\n",dd1,dd2,a,b,c,(K+dd2-dd1)%3);
                if ((K+dd2-dd1)%3 != 0) continue;
                if (a<0 || b<0 || c<0) continue;
                if (max(max(a,b),c) <= N/3){
                    printf("yes\n");
                    goto fuck;
                }
            }
        }
        printf("no\n");
        fuck:;
    }
    return 0;
}