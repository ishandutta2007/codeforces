#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 300005;

int n, q, mx;
int a[MAXN];
pair <llint, int> p[MAXN], sol[MAXN];
deque <int> dq;
vector <int> v;

void bla () {
    mx = dq.front(); dq.pop_front();
    while (!dq.empty()) {
        v.push_back(dq.front());
        dq.pop_front();
    }
}

void ispis (int i) {
    int a = dq.front(); dq.pop_front();
    int b = dq.front(); dq.pop_front();
    sol[i] = make_pair(a, b);
    dq.push_front(b);
    dq.push_front(a);
}

void povecaj () {
    int a = dq.front(); dq.pop_front();
    int b = dq.front(); dq.pop_front();
    if (a > b) {
        dq.push_front(a);
        dq.push_back(b);
    } else {
        dq.push_front(b);
        dq.push_back(a);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        dq.push_back(a[i]);
    }
    for (int i=1; i<=q; i++) {
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p+1, p+1+q);
    int cnt = 0;
    for (int i=1; i<=q; i++) {
        llint val = p[i].first, ind = p[i].second;
        if (val <= n) {
            while (cnt < val-1) {
                povecaj();
                cnt++;
            }
            ispis(ind);
        } else {
            while (cnt < n-1) {
                povecaj();
                cnt++;
            }
            if (v.empty()) bla();
            val -= n-1;
            int pos = (val - 1) % (n-1);
            sol[ind] = make_pair(mx, v[pos]);
        }
    }
    for (int i=1; i<=q; i++) {
        cout << sol[i].first << " " << sol[i].second << endl;
    }
    return 0;
}