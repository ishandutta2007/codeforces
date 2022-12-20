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
        char c;
        cin >> c;
        int out = 0;
        for (char i = 'a'; i < c; i++) {
            out += 25;
        }
        char d;
        cin >> d;
        out += d - 'a' + 1;
        if (d > c) out--;
        cout << out << endl;
    }    
}