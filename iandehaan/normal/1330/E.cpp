#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll h, g;
        cin >> h >> g;
        ll n = (1 << h);
        ll m = (1 << g);
        bool keep[n];
        ll a[n];
        for (int i = 0; i < n; i++) keep[i] = false;
        for (int i = 1; i < n; i++) cin >> a[i];

        priority_queue<pii, vector<pii>, greater<pii>> minheaps[m];
        ll selected[m];
        ll sm = 0;
        for (int i = m-1; i >= 1; i--) {
            int leftchild = 2*i;
            int rightchild = 2*i+1;

            if (leftchild >= m) {
                // leaf node
                minheaps[i].push(mp(a[i], i));
                queue<int> q;
                q.push(i);
                ll mn = a[i];
                ll mnind = i;
                while (!q.empty()) {
                    int top = q.front(); q.pop();
                    int lef = 2*top;
                    int righ = 2*top + 1;
                    if (lef < n) {
                        if (a[lef] < mn) {
                            mn = a[lef];
                            mnind = lef;
                        }
                        if (a[righ] < mn) {
                            mn = a[righ];
                            mnind = righ;
                        }
                        q.push(lef);
                        q.push(righ);
                    }
                }
                selected[i] = mn;
                keep[mnind] = true;
                sm += mn;
            } else {
                ll mx = max(selected[leftchild], selected[rightchild]);

                queue<int> q;
                q.push(i);
                ll mn = a[i];
                ll mnind = i;
                while (!q.empty()) {
                    int top = q.front(); q.pop();
                    int lef = 2*top;
                    int righ = 2*top+1;
                    if (lef < n) {
                        if (a[lef] > mx && a[lef] < mn) {
                            mn = a[lef];
                            mnind = lef;
                        }
                        if (a[righ] > mx && a[righ] < mn) {
                            mn = a[righ];
                            mnind = righ;
                        }
                        q.push(lef);
                        q.push(righ);
                    }
                }

                selected[i] = mn;
                keep[mnind] = true;
                sm += mn;
            }
        }

        cout << sm << endl;
        for (int i = n-1; i >= 1; i--) {
            if (!keep[i]) cout << i << ' ';
        }
        cout << endl;
    }
}