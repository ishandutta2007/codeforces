#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

const int N = 300123;
deque<int> a[N];
int when[N];
int k;

int main() {
    set<pair<int, int>> q;

    int n, T;
    scanf("%d%d", &n, &T);

    for (int t = 1; t <= T; ++t) {
        int type, x;
        scanf("%d%d", &type, &x);

        if (type == 1) {
            a[x].push_back(t);
            q.insert(make_pair(t, x));
            when[++k] = t;
        } else if (type == 2) {
            for (int time : a[x]) {
                auto it = q.find(make_pair(time, x));
                if (it != q.end()) {
                    q.erase(it);
                }
            }
            a[x].clear();
        } else {
            for (auto it = q.begin(); it != q.end() && it->first <= when[x];) {
                int where = it->second;
                if (!a[where].empty() && a[where].front() == it->first) {
                    a[where].pop_front();
                }
                it = q.erase(it);
            }
        }

        printf("%d\n", int(q.size()));
    }

    return 0;
}