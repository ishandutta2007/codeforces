#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define l first
#define r second
typedef pair<ll,ll> seg;
typedef pair<seg,int> pear;

bool contains(seg& a, seg& b) {
    return a.l <= b.l && b.r <= a.r;
}
int main() {
    int n;
    scanf("%d", &n);
    vector<pear> segs(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld",  &segs[i].first.l, &segs[i].first.r);
        segs[i].second = i + 1;
    }
    sort(segs.begin(), segs.end(), [](pear a, pear b) {
        return a.first.l != b.first.l ? a.first.l < b.first.l : a.first.r > b.first.r;
    });
    int ansi = -1, ansj = -1;
    for (int i = 1; i < n; i++) {
        if (contains(segs[i - 1].first, segs[i].first)) {
            ansi = segs[i].second;
            ansj = segs[i - 1].second;
            break;
        }
    }
    printf("%d %d\n", ansi, ansj);
}