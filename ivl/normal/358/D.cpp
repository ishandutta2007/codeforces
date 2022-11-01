#include <cstdio>
#include <algorithm>

using namespace std;

int n;
long long in[3005][3];

long long memo[3005][2];
bool bio[3005][2];
long long dp(int pos, int ac){
     if (pos == n - 1){
        return in[pos][ac];
     }
     if (bio[pos][ac]) return memo[pos][ac];
     bio[pos][ac] = true;
     return memo[pos][ac] = max(dp(pos + 1, 0) + in[pos][ac + 1], dp(pos + 1, 1) + in[pos][ac]);
}

int main(){
    scanf("%d", &n);
    for (int j = 0; j < 3; ++j) for (int i = 0; i < n; ++i) scanf("%I64d", in[i] + j);
    printf("%I64d\n", dp(0, 0));
    return 0;
}