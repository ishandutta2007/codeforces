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

    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        

        if (b == 0) {
            if (c == 0) {
                for (int i = 0; i <= a; i++) {
                    cout << 0;
                }
                cout << endl;
            } else {
                for (int i = 0; i <= c; i++) {
                    cout << 1;
                }
                cout << endl;
            }
        } else if (b == 1) {
            for (int i = 0; i <= a; i++) cout << 0;
            for (int i = 0; i <= c; i++) cout << 1;
            cout << endl;
        } else {
            if (c == 0) {
                int last = 0;
                if (b % 2 == 0) last = 1;
                for (int i = 0; i <= b; i++) {
                    last = (last+1)%2;
                    cout << last;
                }
                for (int i = 0; i < a; i++) cout << 0;
                cout << endl;
            } else if (a == 0) {
                int last = 0;
                if (b % 2 == 1) last = 1;
                for (int i = 0; i <= b; i++) {
                    last = (last+1)%2;
                    cout << last;
                }
                for (int i = 0; i < c; i++) cout << 1;
                cout << endl;
            } else {
                int last = 0;
                for (int i = 0; i < b; i++) {
                    last = (last+1)%2;
                    cout << last;
                }
                if (last == 0) {
                    for (int i = 0; i < a; i++) cout << 0;
                    cout << 1;
                    for (int i = 0; i < c; i++) cout << 1;
                } else {
                    for (int i = 0; i < c; i++) cout << 1;
                    cout << 0;
                    for (int i = 0; i < a; i++) cout << 0;
                }
                cout << endl;
            }
        }
    }
}