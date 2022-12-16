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
        int n, k;
        cin >> n >> k;
        int a[n];
        rep(i, 0, n) cin >> a[i];
        sort(a, a+n);

        int extras = n;
        int lastthing = -1;
        int mex = a[n-1]+1;
        int needmove = 0;
        rep(i, 0, n) {
            if (i != n-1 && a[i] == a[i+1]) {
                continue;
            }

            extras--;
            int gap = a[i] - lastthing - 1;

            //cout << i << ' ' << k << ' ' << extras << ' ' << gap << endl;

            
            

            if (gap <= min(k, extras)) {
                // so awesome and poggers!
                k -= gap;
                extras -= gap;
                needmove += gap;
            } else {
                extras++;
                mex = lastthing + min(k, extras) + 1;
                needmove += min(k, extras);
                break;
            }
            
            lastthing = a[i];
        }

        //cout << mex << ' ' << needmove << endl;

        int unique = 0;
        rep(i, 0, n) {
            if (i == n-1 || a[i] != a[i+1]) unique++;
        }

        priority_queue<int, vi, greater<int>> avail;
        int cnt = 0;
        rep(i, 0, n) {
            if (a[i] < mex) continue;

            if (i != n-1 && a[i] == a[i+1]) {
                cnt++;
                continue;
            }

            cnt++;
            avail.push(cnt);
            cnt = 0;
        }

        while (needmove > 0 && (!avail.empty())) {
            int top = avail.top(); avail.pop();

            if (top > needmove) {
                unique += needmove;
                needmove = 0;
            } else {
                // move all
                unique += top - 1;
                needmove -= top;
            }
        }

        //cout << needmove << endl;

        // rest are dupes
        unique += needmove;
        cout << unique - mex << '\n';
    }
}