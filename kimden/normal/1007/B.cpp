#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int gcd(int x, int y){
    if(!x){
        return y;
    }
    if(!y){
        return x;
    }
    while(x % y){
        x %= y;
        swap(x, y);
    }
    return y;
}

vector<int> lp;
vector<int> primes;
vector<int> divs;


vector<int> st = {336, 236, 136, 126, 556, 455,
                  355, 356, 26, 566, 13, 346, 124, 45, 235, 156, 35, 146, 25, 36, 666,
                  34, 66, 145, 12, 234, 266, 345, 456, 14, 46, 125, 33, 144, 16, 23,
                  134, 166, 245, 255, 334, 366, 445, 344, 246, 56, 135, 446, 256, 335, 466};

int main() {
    ios_base::sync_with_stdio(false);
    divs.resize(100005, 0);
    for(int i = 1; i < 100005; ++i){
        for(int j = i; j < 100005; j += i){
            ++divs[j];
        }
    }
    lp.resize(100005, -1);
    for(int i = 2; i < 100005; ++i){
        if(lp[i] == -1){
            primes.push_back(i);
            lp[i] = i;
            for(ll j = i * ll(i); j < 100005; j += i){
                if(lp[j] == -1){
                    lp[j] = i;
                }
            }
        }
    }
    int n;
    cin >> n;
    int A, B, C, D, E, F, G;
    ll da, db, dc, dd, de, df, dg;
    vector<int> aaa = {0, 4, 5, 6};
    vector<int> bbb = {1, 3, 5, 6};
    vector<int> ccc = {2, 3, 4, 6};
    ll ans = 0;
    ll cur = 0;
    for(int i = 0; i < n; ++i){
        ans = cur = 0;
        cin >> A >> B >> C;
        int a, b, c, d, e, f, g;
        a = A;
        b = B;
        c = C;
        d = gcd(b, c);
        e = gcd(a, c);
        f = gcd(a, b);
        g = gcd(d, f);
        dg = divs[g];
        df = divs[f] - dg;
        de = divs[e] - dg;
        dd = divs[d] - dg;

        dc = divs[c];
        db = divs[b];
        da = divs[a];
        da -= de + df + dg;
        db -= dd + df + dg;
        dc -= dd + de + dg;
        vector<ll> p(7);
        p[0] = da;
        p[1] = db;
        p[2] = dc;
        p[3] = dd;
        p[4] = de;
        p[5] = df;
        p[6] = dg;
        for(auto qq: st){
          //  cerr << qq << endl;
            int x = qq / 100;
            int y = (qq / 10) % 10;
            int z = qq % 10;
            vector<int> w(7, 0);
            ++w[x];
            ++w[y];
            ++w[z];
            cur = 1;
            for(int j = 0; j < 7; ++j){
                switch(w[j]){
                    case 0: break;
                    case 1: cur *= p[j]; break;
                    case 2: cur *= (p[j] * (p[j] + 1)) / 2; break;
                    case 3: cur *= (p[j] * (p[j] + 1) * (p[j] + 2)) / 6; break;
                }
            }
            ans += cur;
        /*    if(cur > 0){
                cerr << x << " " << y << " " << z << " " << cur << " " << ans << endl;
            }*/
        }
        cout << ans << endl;
    }


}