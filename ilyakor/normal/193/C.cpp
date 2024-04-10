#include <ctime>
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

int A[4][4];

string genS() {
    string res;
    for (int i = 0; i < 100000; ++i)
        res += (char)('a' + (rand() >> 5) % 2);
    return res;
}

int calc(string s1, string s2) {
    int res = 0;
    for (int i = 0; i < sz(s1); ++i)
        if (s1[i] != s2[i]) ++res;
    return res;
}

void gen() {
    vector<string> v(4);
    for (int i = 0; i < 4; ++i)
        v[i] = genS();
    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 4; ++j) {
            cout << calc(v[i], v[j]) << " ";
        }
        cout << "\n";
    }
}

int main() {
//  srand(time(0));
//  gen();
    for (int i = 0; i < 4; ++i)
        for (int j = i + 1; j < 4; ++j)
            cin >> A[i][j];
    //for (int L = 1; L <= 1000 * 1000; ++L) {
    for (int fake = 0; fake < 1; ++fake) {
        int l1 = A[0][1], l2 = A[0][2], l3 = A[0][3];
        int x = l1 + l2 - A[1][2];
        if (x < 0 || x % 2 != 0) continue;
        x /= 2;
        int y = l1 + l3 - A[1][3];
        if (y < 0 || y % 2 != 0) continue;
        y /= 2;
        int z = l2 + l3 - A[2][3];
        if (z < 0 || z % 2 != 0) continue;
        z /= 2;
        int c = 0;
        c = max(c, x + y - l1);
        c = max(c, x + z - l2);
        c = max(c, y + z - l3);
        x -= c;
        y -= c;
        z -= c;
        if (x < 0) continue;
        if (y < 0) continue;
        if (z < 0) continue;
        int c1 = l1 - x - y - c;
        if (c1 < 0) continue;
        int c2 = l2 - x - z - c;
        if (c2 < 0) continue;
        int c3 = l3 - y - z - c;                                              
        if (c3 < 0) continue;
        int L = x + y + z + c + c1 + c2 + c3;
        string s0(L, 'a');
        string s1(L, 'a');
        string s2(L, 'a');
        string s3(L, 'a');
        int cur = 0;
        for (int i = 0; i < c; ++i) {
            s1[cur] = s2[cur] = s3[cur] = 'b';
            ++cur;
        }
        for (int i = 0; i < x; ++i) {
            s1[cur] = s2[cur] = 'b';
            ++cur;
        }
        for (int i = 0; i < y; ++i) {
            s1[cur] = s3[cur] = 'b';
            ++cur;
        }
        for (int i = 0; i < z; ++i) {
            s2[cur] = s3[cur] = 'b';
            ++cur;
        }
        for (int i = 0; i < c1; ++i) {
            s1[cur] = 'b';
            ++cur;
        }
        for (int i = 0; i < c2; ++i) {
            s2[cur] = 'b';
            ++cur;
        }
        for (int i = 0; i < c3; ++i) {
            s3[cur] = 'b';
            ++cur;
        }
        if (cur > L) { continue; }
        if (x + y + c + c1 != l1) { continue; }
        if (x + z + c + c2 != l2) { continue; }
        if (y + z + c + c3 != l3) { continue; }
        if (x + z + c1 + c3 != A[1][3]) { continue; }
        if (x + y + c2 + c3  != A[2][3]) { continue; }
        if (y + z  + c1 + c2 != A[1][2]) { continue; }
        printf("%d\n%s\n%s\n%s\n%s\n", L, s0.c_str(), s1.c_str(), s2.c_str(), s3.c_str());
        return 0;
    }
//  }
    cout << "-1\n";
    return 0;
}