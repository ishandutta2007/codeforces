#include <iostream>
#include <algorithm>

#ifdef DEBUG
#define D(x...) fprintf(stderr, x)
#else
#define D(x...)
#endif

#define FO(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

string r;
int c[3];
int n[3];
int p[3];
long long k;

long long cost(long long ns) {
    long long req[3];
    FO(i,0,3)
        req[i] = c[i] * ns;
    FO(i,0,3)
        req[i] = max(req[i]-n[i], 0ll);
    long long tc = 0;
    FO(i,0,3)
        tc += p[i] * req[i];
    return tc;
}

int main() {
    cin >> r;
    FO(i,0,3)
        cin >> n[i];
    FO(i,0,3)
        cin >> p[i];
    cin >> k;

    FO(i,0,r.length()) {
        if (r[i] == 'B') c[0]++;
        if (r[i] == 'S') c[1]++;
        if (r[i] == 'C') c[2]++;
    }

    long long s = 0;
    long long e = 1e13;
    long long b = 0;
    while (s <= e) {
        long long m = (s+e)/2;
        if (cost(m) <= k) {
            b = m;
            s = m+1;
        } else e = m-1;
    }
    cout << b << '\n';

    return 0;
}