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
        char a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        bool found = false;
        pair<int, int> str1 = mp(-1, -1);
        pair<int, int> str2 = mp(-1, -1);
        for (int i = 0; i < n; i++) {
            if (a[i] == '0') {
                if ((n-1)-(i+1) + 1 >= n/2) {
                    // first string is from here to the end
                    str1 = mp(i+1, n);
                    // second string is from here+1 to the end
                    str2 = mp(i+2, n);
                } else if ((i-1)-0 +1 >= n/2) {
                    // first string is from the start to here-1
                    str2 = mp(1, i);
                    // second string is from the start to here
                    str1 = mp(1, i+1);
                }
            }
            if (str1 != mp(-1, -1)) {
                found = true;
                break;
            }
        }

        if (!found) {
            if (n % 2 == 1) {
                str1 = mp(1, n/2+1);
                str2 = mp(n/2+1, n);
            } else {
                str1 = mp(1, n/2);
                str2 = mp(n/2+1, n);
            }
        }

        cout << str1.first << ' ' << str1.second << ' ' << str2.first << ' ' << str2.second << endl;
    }
}