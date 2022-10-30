#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int main() {
    long long x1,y1,x2,y2;
    scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
    printf("%lld\n", max(abs(x1-x2),abs(y1-y2)));
}