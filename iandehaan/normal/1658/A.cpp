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
        int n;
        cin >> n;
        int lastmale = -5;
        int out = 0;
        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            if (c == '0') {
                if (lastmale == i-1) out+=2;
                if (lastmale == i-2) out++;
                lastmale = i;
            }
        }
        cout << out << endl;
    }
}