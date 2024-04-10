#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Tree {
    typedef ll T;
    static const T LOW = 0;
    T f(T a, T b) { return a+b; } // (any associative fn )
    vector<T> s; int n;
    Tree(int n = 0, T def = 0) : s(2*n, def), n(n) {}
    void update(int pos, T val) {
        //cout << "updating " << pos << " with " << val << endl;
        for (s[pos += n] = val; pos > 1; pos /= 2)
        s[pos / 2] = f(s[pos & (~1)], s[pos | 1]);
    }
    T query(int b, int e) { // query [ b , e)
        //cout << b << ' ' << e << endl;
        if (b >= e) return 0;
        //cout << "past here" << endl;
        T ra = LOW, rb = LOW;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
        if (b % 2) ra = f(ra, s[b++]);
        if (e % 2) rb = f(s[--e], rb);
        }
        //cout << "here" << endl;
        //cout << f(ra, rb) << endl;
        return f(ra, rb);
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;
    Tree rage(n, 1);
    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    for (int i = 0; i < n; i++) rage.update(i, a[i]);

    //ll test = rage.query(0, 1);
    //cout << " blah: " << test << endl;

    ll out = ((ll)1)<<62;
    ll cnt = 1;
    ll begin = 0;
    for (int i = 0; i < n; i++) {
        if (i >= 1 && a[i-1] != a[i]) {
            cnt = 1;
            begin = i;
        }

        if (i < n-1 && a[i] == a[i+1]) {
            cnt++;
            continue;
        }

        ll local = ((ll)1)<<62;
        ll needed = k-cnt;
        ll target = a[i];
        if (needed <= 0) {
            cout << 0 << endl;
            return 0;
        }

        ll leftside = rage.query(0, begin);
        leftside = abs(begin*(target-1)-leftside);
        ll rightside = rage.query(i+1, n);
        rightside = abs(rightside-(n-(i+1))*(target+1));
        local = min(local, leftside+rightside+needed);

        //cout << i << ' ' << leftside << ' ' << rightside << endl;

        if (begin >= needed) {
            local = min(local, leftside+needed);
        }

        if (i < (n-needed)) {
            local = min(local, rightside+needed);
        }
        out = min(out, local);

        //cout << "need " << needed << endl;
       /* ll target = a[i];
        // only left
        if (begin >= needed) {
            //cout << "only left" << endl;
            ll amt = rage.query(0, begin);
            amt = abs(begin*target - amt);
            local = min(local, amt);
            //cout << local << endl;
        } else {
            // some left some right
            
            leftside = begin*target - leftside;
            ll neededonright = needed-begin;
            ll rightside = rage.query(i+1, n);
            rightside = abs(rightside-(n-(i+1))*target);

            //assert(begin+neededonright==needed);
            local = min(local, leftside+rightside);
        }

        // only right
        if (i < (n-needed)) {
            //cout << "only right" << endl;
            ll amt = rage.query(n-needed, n);
            amt = abs(amt-needed*target);
            //cout << "blah2 " << needed*target << endl;
            //cout << amt << endl;
            local = min(local, amt);
        } else {
            // some left some right
            ll rightside = rage.query(i+1, n);
            ll gotonright = n-i-1;
            rightside = abs(rightside-gotonright*target);
            ll neededonleft = needed-gotonright;
            ll leftside = rage.query(0, neededonleft);
            leftside = abs(neededonleft*target - leftside);
            assert(neededonleft + gotonright == needed);
            local = min(local, leftside+rightside);
        }
        //cout << local << endl;
        //cout << local << endl;
        assert(local >= 0);
        out = min(out, local);*/
    }
    cout << out << endl;
}