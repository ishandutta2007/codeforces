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

    int n;
    cin >> n;

    int a[200000];
    for (int i = 0; i < 200000; i++) a[i] = 0;
    multiset<int> b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 0; i < 200000; i++) {
        b.insert(a[i]);
        //if (a[i] != 0) cout << i << ' ' << a[i] << endl;
    }

    //for (int thing : b) if (thing != 0) cout << thing << endl;

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        char cmd;
        cin >> cmd;
        int x;
        cin >> x;
        if (cmd == '+') {
            //cout << "erasing " << a[x] << endl;
            b.erase(b.find(a[x]));
            a[x]++;
            b.insert(a[x]);
        } else {
            b.erase(b.find(a[x]));
            a[x]--;
            b.insert(a[x]);
        }

        bool four = false;
        bool two1 = false;
        bool two2 = false;
        auto iter = b.end();
        iter--;
        for (; ; iter--) {
            int amt = *iter;
            //cout << amt << endl;
            if (four && two1 && two2) break;
            if (amt < 2) break;
            if (amt < 4 && (!four)) break;

            if ((!four) && amt >= 4) {
                four = true;
                amt -= 4;
            }
            if ((!two1) && amt >= 2) {
                two1 = true;
                amt -= 2;
            }
            if ((!two2) && amt >= 2) {
                two2 = true;
                amt -= 2;
            }
            if (iter == b.begin()) break;
        }
        if (four && two1 && two2) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}