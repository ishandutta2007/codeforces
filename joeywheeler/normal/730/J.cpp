#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for (int i = (a); i < (b); i++)
#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

int n;
int a[105], b[105];
pair<int,int> dp[105][105*105];
bool seen[105][105*105];
int tsa;

// num bot, time
pair<int,int> f(int i, int sb) {
    if (seen[i][sb]) return dp[i][sb];
    seen[i][sb] = true;
    if (i == n) {
        if (sb >= tsa) {
            return dp[i][sb] = make_pair(0, 0);
        } else {
            return dp[i][sb] = make_pair(105,0);
        }
    } else {
        // don't take
        auto p = f(i+1, sb);
        p.second += a[i];
        auto op = f(i+1, sb+b[i]);
        op.first += 1;
        return dp[i][sb] = min(op, p);
    }
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        scanf("%d", a+i);
        tsa += a[i];
    }
    FO(i,0,n) scanf("%d", b+i);

    auto p = f(0,0);
    printf("%d %d\n", p.first, p.second);

    return 0;
}