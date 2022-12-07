#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, ll> pii;
const int N = 100005;

int a[N];
pii save[N];
map<int, ll> ans;

int n;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void build() {
    int top = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < top; j++) save[j].first = gcd(save[j].first, a[i]);
        save[top++] = make_pair(a[i], 1LL);
        int sn = 1;
        for (int j = 1; j < top; j++) {
            if (save[sn - 1].first == save[j].first) save[sn - 1].second += save[j].second;
            else save[sn++] = save[j];
        }
        top = sn;
        for (int j = 0; j < top; j++) {
            ans[save[j].first] += save[j].second;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    build();
    int q;
    scanf("%d", &q);
    while (q--) {
        int x;
        scanf("%d", &x);
        printf("%lld\n", ans[x]);
    }
    return 0;
}