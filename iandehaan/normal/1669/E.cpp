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
        ll numstart[26];
        ll numend[26];
        ll numeq[26][26];
        ll out = 0;
        for (int i = 0; i < 26; i++) {
            numstart[i] = 0;
            numend[i] = 0;
            for (int j = 0; j < 26; j++) numeq[i][j] = 0;
        }
        for (int i = 0; i < n; i++) {
            char c, d;
            cin >> c >> d;
            int a = c - 'a';
            int b = d - 'a';
            out += numstart[a] - numeq[a][b];
            out += numend[b] - numeq[a][b];
            numeq[a][b]++;
            numstart[a]++;
            numend[b]++;
        }
        cout << out << endl;
    }
}