#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pll;

const int buben = 316;

int n;
vector<int> steps, last, a;
vector<int> block;

void recalc(int l, int r)
{
    for (int i = r; i >= l; --i) {
        if (i + a[i] < n && block[i + a[i]] == block[i]) {
            steps[i] = steps[i + a[i]] + 1;
            last[i] = last[i + a[i]];
        } else {
            steps[i] = 0;
            last[i] = i;
        }
    }
}

int main()
{

    //freopen("input.txt", "r", stdin);

    int q;
    scanf("%d%d", &n, &q);

    block.resize(n);
    steps.resize(n), last.resize(n), a.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        block[i] = i / buben;
    }

    recalc(0, n - 1);

    while (q--) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int pos;
            scanf("%d", &pos);
            --pos;
            int ans = 0;
            int prev = -1;
            while (pos < n) {
                prev = pos;
                if (last[pos] != pos) {
                    ans += steps[pos];
                    pos = last[pos];
                } else {
                    ++ans;
                    pos += a[pos];
                }
            }
            printf("%d %d\n", prev + 1, ans);
        } else {
            int pos, val;
            scanf("%d%d", &pos, &val);
            --pos;
            a[pos] = val;
            recalc(block[pos] * buben, pos);
        }
    }

}