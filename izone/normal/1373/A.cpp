#include<cstdio>
#include<algorithm>
using namespace std;
void Solve(){
    long long a, b, c, r1=-1,r2=-1;
    scanf("%lld%lld%lld",&a,&b,&c);
    if(a<c){
        r1=1;
    }
    if(a*b>c){
        r2=b;
    }
    printf("%lld %lld\n",r1,r2);
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}