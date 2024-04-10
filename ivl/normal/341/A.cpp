#include <cstdio>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b){
     if (b) return gcd(b, a % b);
     return a;
}

int n;
int in[100005];

int main(){
    scanf("%d", &n);
    long long rez = 0;
    long long pom = 0;
    for (int i = 0; i < n; ++i){
        scanf("%d", in + i);
    }
    sort(in, in + n);
    for (int i = 0; i < n; ++i){
        rez += in[i];
        rez += 2 * ((long long)i * (long long)in[i] - pom);
        pom += in[i];
    }
    long long x = gcd(rez, (long long)n);
    printf("%I64d %I64d\n", rez / x, (long long)n / x);
    return 0;
}