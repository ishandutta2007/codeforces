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

ll best(string n, vector<char> nums) {
    //sort(all(nums));

    for (char x : nums) {
        if (x > n[0]) {
            // fill it with this man, followed by smallest man
            ll out = x-'0';
            for (int i = 0; i < sz(n)-1; i++) {
                out *= 10;
                out += nums[0]-'0';
            }
            return out;
        } else if (x == n[0]) {
            if (sz(n) == 1) {
                return x-'0';
            }

            string newstr;
            for (int i = 1; i < sz(n); i++) newstr.pb(n[i]);

            ll intout = best(newstr, nums);
            if (intout != -1) {
                ll thousands = 1;
                for (int i = 0; i < sz(n)-1; i++) thousands *= 10;
                intout += thousands*(x-'0');
                return intout;
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string n;
        int k;
        cin >> n >> k;

        unordered_set<char> nums;
        int ind = 0;
        while (ind < sz(n) && nums.size() < k) {
            if (nums.count(n[ind]) != 0) {
                ind++;
            } else {
                if (nums.size() < k-1) {
                    nums.insert(n[ind]);
                    ind++;
                } else {
                    break;
                }
            }
        }
        if (ind == sz(n)) {
            // we can just do n
            cout << n << endl;
            continue;
        }

        //cerr << "here" << endl;


        // we can't just do n
        vector<char> vecnums;
        for (char x : nums) vecnums.pb(x);

        ll out = -1;
        for (char extradig = '0'; extradig <= '9'; extradig++) {
            if (nums.count(extradig) != 0) continue;

            vector<char> newvec = vecnums;
            newvec.pb(extradig);
            sort(all(newvec));
            if (out == -1) out = best(n, newvec);
            else {
                ll blahout = best(n, newvec);
                if (blahout != -1) out = min(out, blahout);
            }
        }

        cout << out << endl;
    }
}