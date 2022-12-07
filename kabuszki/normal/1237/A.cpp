#include<bits/stdc++.h>
using namespace std;

// #define int long long

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,a) FOR(i,0,(a)-1)
#define SIZE(v) (int)(v).size()
#define PB push_back
#define EB emplace_back
#define IN insert
#define ER erase
#define ALL(a) (a).begin(),(a).end()
#define ST first
#define ND second

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VII;

void jebaj() {
    int n;
    cin >> n;
    VI v, w;
    int k = 0;
    REP(i, n) {
        int a;
        cin >> a;
        if (a % 2 == 0) {
            v.PB(a/2);
            w.PB(0);
        }
        else {
            v.PB(a);
            w.PB(1);
            k++;
        }
    }
    k /= 2;
    REP(i, n) {
        if (w[i] == 0) cout << v[i] << "\n";
        else {
            if (k) {
                cout << (int)(std::floor(double(v[i]) / 2.0)) + 1<< "\n";
                k--;
            } else {
                cout << int(std::floor(double(v[i]) / 2.0))<< "\n";
            }
        }
    }
}

// #undef int

int main() {

    //#define int long long
    int t = 1;
    //cin >> t;
    FOR(i, 1, t) {
        //cout << "Case #" << i << ": ";
        jebaj();
    }
    return 0;
}