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
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a+n);

    int curr = 0;
    int bst = 1;
    int bstend = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || (a[i] != a[i-1] && a[i+1] != a[i])) {
            if (i != 0 && abs(a[i-1]-a[i]) <= 1) curr++;
            if (curr > bst) {
                bst = curr;
                bstend = i;
            }
            curr = 1;
        } else {
            if (abs(a[i-1]-a[i]) <= 1) {
                curr++;
                if (curr > bst) {
                    bst = curr;
                    bstend = i;
                }
            } else {
                curr = 1;
            }
        }
    }

    cout << bst << endl;
    int bststart = bstend - bst + 1;
    bool blah = true;
    for (int i = bststart; i < bstend; i+=2) {
        cout << a[i] << ' ';
        if (i == bstend-1) blah = false;
    } 
    cout << a[bstend] << ' ';

    for (int i = blah ? bstend-1 : bstend-2; i > bststart; i-=2) {
        cout << a[i] << ' ';
    }
    cout << endl;

}