#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

const int N = 200222;
int t[N];
int border[N];
ll k, b, c;
vector<int> poses[5];

ll cost(ll steps) {
    return ll(steps / 5) * b + ll(steps % 5) * c;
}

int main() {
    int n;
    cin >> n >> k >> b >> c;
    b = min(b, 5 * c);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", t + i);
        t[i] += int(1e9);
    }
    sort(t, t + n);
    for (int i = 0; i < 5; ++i) poses[i].reserve(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            poses[(t[i] + j) % 5].push_back(t[i] + j); 
        }
    }

    ll ans = 1e18;
    for (int rem = 0; rem < 5; ++rem) {
        int last = 0;

        ll sum = 0;
        ll add = 0;
        priority_queue<ll> q;

        for (int i = 0; i < n; ++i) {
            int pos = poses[rem][i]; 
            while (last < n && t[last] <= pos) {
                ll value = cost(pos - t[last]);      
                
                q.push(value - add);
                sum += value - add;

                while (q.size() > size_t(k)) {
                    sum -= q.top(); q.pop();
                }
                
                if (int(q.size()) == k) {
                    ans = min(ans, sum + ll(k) * add);
                }

                ++last;
            }

            if (i + 1 < n) {
                add += ll((poses[rem][i + 1] - pos) / 5) * b;
            }
        }
    }

    cout << ans << endl;

    return 0;
}