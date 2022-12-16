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

    int n, k;
    cin >> n >> k;
    int num[300];
    pair<int, int> things[n];
    bool used[n];
    for (int i = 0; i < 300; i++) num[i] = 0;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        things[i] = mp(l, r);
        used[i] = false;
        for (int j = l; j <= r; j++) num[j]++;
    }

    vector<int> out;
    int decr = 0;

    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < 300; i++) {
        while ((!q.empty()) && q.top() < i) {
            //cout << "hi" << endl;
            q.pop();
            decr--;
        }

        while (num[i] - decr > k) {
            //cout << num[i] << ' ' << decr << ' ' << k << endl;
            int best = 0;
            int bestind = -1;
            for (int j = 0; j < n; j++) {
                if (used[j]) continue;
                if (things[j].first <= i && things[j].second > best) {
                    best = things[j].second;
                    bestind = j;
                }
                
            }
            used[bestind] = true;
                out.pb(bestind);
                q.push(best);
            decr++;
        }
    }
    cout << out.size() << endl;
    for (int thing : out) cout << thing+1 << ' ';
    cout << endl;
}