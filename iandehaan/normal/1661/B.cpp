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

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int out = 15;
        int x2;
        cin >> x2;

        for (int addamt = 0; addamt <= 15; addamt++) {
            int x = x2;
            int ops = addamt;
            x += addamt;
            x %= 32768;
            while (x != 0) {
                //cout << x << endl;
                x *= 2;
                x %= 32768;
                ops++;
            }
            out = min(out, ops);
        }
        cout << out << ' ';
        
    }
    cout << endl;
}