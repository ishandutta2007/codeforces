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
    rep(i, 0, n) cin >> a[i];

    int prefmn[n];
    prefmn[0] = a[0];
    for (int i = 1; i < n; i++) {
        prefmn[i] = min(prefmn[i-1], a[i]);
    }
    int postmn[n];
    postmn[n-1] = a[n-1];
    for (int i = n-2; i >= 0; i--) {
        postmn[i] = min(postmn[i+1], a[i]);
    }

    int out = 1e9;
    // Case 1: Two things that don't have anything to do with each other
    for (int i = 0; i < n; i++) {
        int shots1 = (a[i]+1) / 2;
        int mnleft = 1e9;
        if (i > 0) mnleft = min(mnleft, prefmn[i-1]);
        if (i+1 < n) mnleft = min(mnleft, postmn[i+1]);
        int shots2 = (mnleft+1)/2;
        out = min(out, shots1+shots2);
    }
    
    // Case 2: distance of one. Shoot middle until one breaks, then shoot sides.
    for (int i = 1; i < n-1; i++) {
        int shots1 = min(a[i-1], a[i+1]);
        int shots2 = (max(a[i-1], a[i+1]) - min(a[i-1], a[i+1]) + 1) / 2;
        out = min(out, shots1+shots2);
    }

    // Case 3: adjacent
    for (int i = 0; i < n-1; i++) {
        // a[i], a[i+1]
        // shoot smaller one until it is half size of bigger one
        // then shoot bigger to completion
        int smol = min(a[i], a[i+1]);
        int big = max(a[i], a[i+1]);
        if (smol <= (big+1)/2) {
            // just shoot big
            out = min(out, (big+1)/2);
        } else {
            int hi = (smol+1) / 2;
            int lo = 0;
            while (abs(lo-hi) > 2) {
                int mid = (hi+lo)/2;
                int newsmol = smol - 2*mid;
                int newbig = big - mid;
                if (newsmol <= (newbig+1)/2) {
                    // went far enough
                    hi = mid;
                } else {
                    lo = mid;
                }
            }
            int amt = lo;
            for (int mid = lo; mid <= hi; mid++) {
                int newsmol = smol - 2*mid;
                int newbig = big - mid;
                if (newsmol <= (newbig+1)/2) {
                    amt = mid;
                    break;
                }
            }


            int numshots2 = (big - amt + 1) / 2;
            out = min(out, amt+numshots2);
        }
    }


    cout << out << endl;
    /*for (int i = 0; i < n; i++) {
        // shoot here until something breaks
        vector<int> thingshere;
        thingshere.pb(a[i]);
        if (i != 0) thingshere.pb(a[i-1]);
        if (i != n-1) thingshere.pb(a[i+1]);
        sort(all(thingshere));

        int numshots1 = thingshere[0];

        int mnleft = thingshere[1] - numshots1;

        if (i >= 2) mnleft = min(mnleft, prefmn[i-2]);
        if (i+2 < n) mnleft = min(mnleft, postmn[i+2]);

        out = min(numshots1 + mnleft, out);
        
    }
    cout << out << endl;*/
}