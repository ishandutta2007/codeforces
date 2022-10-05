#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define X first
#define Y second

ll l, r;

int main(){
    scanf("%lld%lld", &l, &r);
    puts("YES");
    for(; l <= r; l += 2){
        printf("%lld %lld\n", l, l + 1);
    }
    return 0;
}