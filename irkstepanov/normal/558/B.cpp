#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pll;

int main()
{

    //freopen("input.txt", "r", stdin);

    int n;
    scanf("%d", &n);

    map<int, int> cnt;
    map<int, int> l, r;

    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        ++cnt[a];
        if (!l.count(a)) {
            l[a] = i;
        }
        r[a] = i;
    }

    int maxcnt = 0;
    for (auto& it : cnt) {
        if (it.second > maxcnt) {
            maxcnt = it.second;
        }
    }

    int besti = 0, bestj = n - 1;
    for (auto& it : cnt) {
        if (it.second == maxcnt) {
            if (r[it.first] - l[it.first] < bestj - besti) {
                besti = l[it.first];
                bestj = r[it.first];
            }
        }
    }

    cout << besti + 1 << " " << bestj + 1 << "\n";

}