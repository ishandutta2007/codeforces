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

vector<int> ans(vector<int> &inp, vector<int> &pref, int l, int r) {
    //int n = sz(inp);

    int out = pref[r];
    if (l != 0) out -= pref[l-1];
    //cout << " hi" << out << endl;
    if (out == 0) {
        vector<int> outv;
        return outv;
    }
    if (out % 2 == 0) {
        vector<int> outv = ans(inp, pref, l, r-1);
        outv.pb(r+1);
        return outv;
    }

    if (inp[r] == out) {
        vector<int> outv;
        outv.pb(r+1);
        return outv;
    }


    // the hard part :(
    // find x such that a[l...x-1] - a[x+1...r] == 0
    int lo = l;
    int hi = r;

    int startpos = out - inp[r];

    int numiters = 30;
    while (numiters--) {
        int mid = (lo+hi)/2;

        int fromleft = 0;
        if (mid != 0) fromleft = pref[mid-1];
        if (l != 0) fromleft -= pref[l-1];

        int fromright = pref[r];
        if (mid >= 0) fromright -= pref[mid];

        int midval = fromleft - fromright;

        //cout << mid << ' ' << midval << endl;

        if (midval == 0) {
            vector<int> outv;
            outv.pb(mid+1);
            return outv;
        } else if (midval > 0) {
            if (startpos > 0) {
                //lo = mid+1;
                hi = mid-1;
            } else {
                //hi = mid-1;
                lo = mid+1;
            }
        } else {
            if (startpos < 0) {
                //lo = mid+1;
                hi = mid-1;
            } else {
                //hi = mid-1;
                lo = mid+1;
            }
        }
    }
    

    for (int mid = lo-5; mid <= hi+5; mid++) {
        if (mid < l || mid > r) continue;

        int fromleft = 0;
        if (mid != 0) fromleft = pref[mid-1];
        if (l != 0) fromleft -= pref[l-1];

        int fromright = pref[r];
        if (mid >= 0) fromright -= pref[mid];

        int midval = fromleft - fromright;

        if (midval == 0) {
            vector<int> outv;
            outv.pb(mid+1);
            return outv;
        }
    }

    for (int mid = l; mid <= r; mid++) {
        if (mid < l || mid > r) continue;

        int fromleft = 0;
        if (mid != 0) fromleft = pref[mid-1];
        if (l != 0) fromleft -= pref[l-1];

        int fromright = pref[r];
        if (mid >= 0) fromright -= pref[mid];

        int midval = fromleft - fromright;

        if (midval == 0) {
            vector<int> outv;
            outv.pb(mid+1);
            return outv;
        }
    }

    while (true) {
        // inf loop if we haven't found anything... :(
    }
    
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> vals(n);
        vector<int> pref(n);
        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            if (c == '+') {
                if (i % 2 == 0) vals[i] = 1;
                else vals[i] = -1;
            } else {
                if (i % 2 == 0) vals[i] = -1;
                else vals[i] = 1;
            }


            if (i == 0) pref[i] = vals[i];
            else pref[i] = pref[i-1] + vals[i];

            //cout << i << ' ' << vals[i] << endl;
        }

        while (q--) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            vector<int> outv = ans(vals, pref, l, r);
            cout << sz(outv) << endl;
            if (sz(outv) != 0) {
                for (int x : outv) cout << x << ' ';
                cout << endl;
            }
        }
    }
}