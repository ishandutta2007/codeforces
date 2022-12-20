#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        int numbits[20];
        int newbits[20];
        for (int i = 0; i < 20; i++) {
            numbits[i] = 0;
            newbits[i] = 0;
        }
        for (int i = l; i <= r; i++) {
            for (int j = 0; j < 20; j++) {
                if (i & (1 << j)) numbits[j]++;
            }
        }

        
        for (int i = l; i <= r; i++) {
            int x;
            cin >> x;
            for (int j = 0; j < 20; j++) {
                if (x & (1 << j)) newbits[j]++;
            }
        }

        int out = 0;
        for (int i = 0; i < 20; i++) {
            //cout << i << ' ' << numbits[i] << ' ' << newbits[i]
            if (numbits[i] != newbits[i]) out |= (1 << i);
        }

        cout << out << endl;
    }
}