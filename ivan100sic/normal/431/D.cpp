#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long BK[100][100];

void napravi_bk(){
    BK[0][0] = 1;
    int i,j;
    for (i=1; i<=80; i++) BK[i][0] = 1;
    for (i=1; i<=80; i++){
        for (j=1; j<=80; j++){
            BK[i][j] = BK[i-1][j] + BK[i-1][j-1];
        }
    }
}

long long f(long long n,int k){
    long long rez=0;
    for (long long i=62; i>=0; i--){
        if (((1ll<<i)&n)>0 && k>=0){
            n -= 1ll << i;
            rez += BK[i][k];
            k--;
        }
    }
    if (n==0 && k==0) rez++;
    return rez;
}

long long A,B;

int main(){
    napravi_bk();
    //return BK[5][4];
    scanf("%lld%lld",&A,&B);
    long long l,r,m,o;
    r = 1000000000000000000;
    l = 1;
    while (l<=r){
        m = (l+r)/2;
        //printf("%lld %lld %lld\n",m,f(2*m,B),f(m,B));
        if (f(2*m,B) - f(m,B) >= A){
            o = m;
            r = m-1;
        } else {
            l = m+1;
        }
    }
    printf("%lld\n",o);
    return 0;
}