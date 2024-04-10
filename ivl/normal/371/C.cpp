#include <cstdio>

using namespace std;

char in[105];

int x, y, z;

int a, b, c, d, e, f;
long long r;

bool check(long long a, long long b, long long c){
     if (a < 0) a = 0;
     if (b < 0) b = 0;
     if (c < 0) c = 0;
     return r >= a * d + b * e + c * f;
}

int main(){
    scanf("%s", in);
    for (int i = 0; in[i] != '\0'; ++i){
        if (in[i] == 'B') ++x;
        if (in[i] == 'S') ++y;
        if (in[i] == 'C') ++z;
    }
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    scanf("%I64d", &r);
    long long lo = 0, hi = 1000000000000000LL, mid = (lo + hi) / 2;
    while (lo != hi){
          if (check(mid * x - a, mid * y - b, mid * z - c)) lo = mid;
          else hi = mid - 1;
          mid = (lo + hi + 1) / 2;
    }
    printf("%I64d\n", lo);
    return 0;
}