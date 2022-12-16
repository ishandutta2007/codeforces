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

// we know what characters are in [0, pos-1]
// find first position i such that
// query(i, pos) is 1 more than the number of unique in [i, pos-1]
// then a[pos] == a[i-1]
// to reduce queries: only check i such that a[i-1] is last occ. of a char

#define MAXN 1010

char out[MAXN];
int n;

char query1(int pos) {
    cout << "? 1 " << pos+1 << endl;
    char x;
    cin >> x;
    return x;
}

int query2(int pos1, int pos2) {
    if (pos1 == pos2) return 1;
    cout << "? 2 " << pos1+1 << ' ' << pos2+1 << endl;
    int x;
    cin >> x;
    return x;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) out[i] = 'A'; // unknown

    out[0] = query1(0);

    int prevsm = 1;
    rep(i, 1, n) {
        int newsm = query2(0, i);
        if (newsm > prevsm) {
            out[i] = query1(i);

            prevsm = newsm;
        }
    }

   

    rep(i, 0, n) {
        if (out[i] != 'A') {
            continue;
        }

        vector<int> specpos;
        set<int> blah;
        for (int j = i-1; j >= 0; j--) {
            if (blah.count(out[j]) == 0) specpos.pb(j);
            blah.insert(out[j]);
        }
        reverse(all(specpos));

        int lo = -1;
        int hi = sz(specpos);
        while (hi-lo > 1) {
            int mid = (hi+lo)/2;
            //cout << "blah " << mid << ' ' << specpos[mid] << endl;
            int res = query2(specpos[mid]+1, i);
            set<char> unq;
            rep(j, specpos[mid]+1, i) {
                unq.insert(out[j]);
            }
            if (sz(unq) < res) {
                // unique after here!
                hi = mid;
            } else {
                lo = mid;
            }
        }
        //cout << i << ' ' << lo << ' ' << hi << endl;
        out[i] = out[specpos[hi]];

    }
    cout << "! ";
    rep(i, 0, n) cout << out[i];
    cout << endl;
}