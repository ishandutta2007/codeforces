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
        string a;
        cin >> a;
        int n = sz(a);
        int lastone = -1;
        for (int i = 0; i < n; i++) if (a[i] == '1') lastone = i;
        int numzeroes = 0;
        int out = 0;
        for (int i = 0; i < n; i++) {
            if (i < lastone) {
                if (a[i] == '0') numzeroes++;
                continue;
            }
            
            if (numzeroes > 0) {
                if (a[i] == '0') numzeroes++;
                continue;
            }
            out++;
            if (a[i] == '0') numzeroes++;
            
        }
        cout << out << endl;
    }
}