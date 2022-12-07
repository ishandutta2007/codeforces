#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);
const int N = 100111;
struct cell {
    char a;
    int count;

    bool operator<(const cell& A) const {
        return count < A.count;
    }
} a[N], b[N];

int w[N];
int gcd(int a, int b) {
    while (a && b) {
        if (a > b) a %= b;
        else b %= a;
    }
    return a + b;
}

int fath(int x) {
    if (w[x] != x) w[x] = fath(w[x]);
    return w[x];
}

void un(int x, int y) {
    w[fath(x)] = fath(y);
}
char ans[N];

int main() {
    int n;
    cin >> n;
    int sum = 0;
    int have_odd = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].count;
        if (a[i].count & 1) ++have_odd;
        a[i].a = 'a' + i;
        sum += a[i].count;
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i) b[i] = a[i];
    int who = 0; 
    for (int i = 0; i < n; ++i) {
        if (a[i].count & 1) who = i;
    }

    int need_odd = sum & 1;
    if (need_odd != have_odd) {
        printf("%d\n", 0);
        for (int i = 0; i < n; ++i) {
            while (a[i].count--) {
                putchar(a[i].a);
            }
        }
        puts("");
        return 0;
    }
    if (n == 1) {
        cout << sum << endl;
        for (int i = 0; i < sum; ++i) putchar(a[0].a);
        cout << endl;
        return 0;
    }

    for (int k = 1; k <= sum; ++k) {
        if (sum % k) continue;
        for (int i = 0; i < n; ++i) a[i] = b[i];
        for (int i = 0; i < sum; ++i) w[i] = i;
        
        for (int i = 0; i < sum; ++i) {
            un(i, sum - i - 1);
            un(i, (i + k + k) % sum);
        }
        
        map<int, int> q;
        for (int i = 0; i < sum; ++i) {
            q[fath(i)] += 1;
        }

        vector<pair<int, int>> t; 
        for (auto it : q) {
            t.push_back(make_pair(it.second, it.first));
        }
        sort(begin(t), end(t));

        map<int, int> color;
        if (sum & 1) {
            if (a[who].count < t[0].first) {
                continue;
            }
            color[t[0].second] = a[who].a;
            a[who].count -= t[0].first;
        }
        int current = 0; 
        bool done = true;
        for (int i = (sum & 1); i < t.size(); ++i) {
            if (current >= n) {
                done = false;
                break;
            }
            if (a[current].count >= t[i].first) {
                a[current].count -= t[i].first;
                color[t[i].second] = a[current].a;
            } else {
                ++current;
                --i;
            }
        }

        if (done) {
            cout << sum / gcd(sum, k) << endl;
            for (int i = 0; i < sum; ++i) putchar(color[fath(i)]);
            cout << endl;
            return 0;
        }
    }

    printf("%d\n", 0);
        for (int i = 0; i < n; ++i) {
            while (a[i].count--) {
                putchar(a[i].a);
            }
        }
        puts("");
        return 0;

    return 0;
}