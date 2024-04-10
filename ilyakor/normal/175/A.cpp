#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;
typedef long long ll;

template<class T> T abs(T x) { return x > 0 ? x : (-x); }
template<class T> T sqr(T x) { return x * x; }

const int M = 1000000;

int main() {
    string s;
    cin >> s;
    int64 x = 0;
    int64 res = -1;
    for (int i = 0; i < sz(s); ++i) {
        if (x == 0 && i > 0) break;
        x = x * 10LL + (int64)(s[i] - '0');
        if (x > M) break;
        
        int64 y = 0;
        for (int j = i + 1; j < sz(s); ++j) {
            if (y == 0 && j - i - 1 > 0) break;
            y = y * 10LL + (int64)(s[j] - '0');
            if (y > M) break;

            int64 z = 0;
            for (int k = j + 1; k < sz(s); ++k) {
                if (z == 0 && k - j - 1 > 0) break;
                z = z * 10LL + (int64)(s[k] - '0');
                if (z > M) break;

                if (k == sz(s) - 1) {
                    //cerr << x << " " << y << " " << z << "\n";
                    res = max(res, x + y + z);
                }
            }
        }       
    }

    cout << res << "\n";
    return 0;
}