#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[100005];

int cnt[100005];
#define int long long
int memo[100005];
bool bio[100005];
int dp(int pos){
    if (pos < 0) return 0;
    int &r = memo[pos];
    if (bio[pos]++) return r;
    return r = max(dp(pos - 1), cnt[pos] * pos + dp(pos - 2));
}
#undef int

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        scanf("%d", a + i);
        ++cnt[a[i]];
    }
    for (int i = 0; i <= 100000; ++i) dp(i);
    printf("%I64d\n", dp(100000));
    return 0;
}