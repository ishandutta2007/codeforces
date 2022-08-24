#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

#define MAXN 2000010

int N;
char ans[MAXN];

bool dstr(int x, int y) {
    return y ? (x >= y) : (x == 0);
}
bool check(int a4, int a7, int a47, int a74, char bef) {
    if (bef == '7') {
        return check(a7, a4, a74, a47, '4');
    }
    if (a4 < 0 || a7 < 0 || a47 < 0 || a74 < 0) {
        return 0;
    }
    if (dstr(a4 + 1, a47) && dstr(a7, a47) && a74 == a47 - 1) {
        return 1;
    }
    if (dstr(a4 + 1, a47 + 1) && dstr(a7, a47) && a74 == a47) {
        return 1;
    }
//cout<<"false : "<<a4<<" "<<a7<<" "<<a47<<" "<<a74<<endl;
    return 0;
}

int main() {
    int a4, a7, a47, a74;
    int i;
    
    for (; ~scanf("%d%d%d%d", &a4, &a7, &a47, &a74); ) {
        N = a4 + a7;
        char bef = 0;
        for (i = 0; i < N; ++i) {
//cout<<a4<<" "<<a7<<" "<<a47<<" "<<a74<<"  "<<bef<<endl;
            if (check(a4 - 1, a7, a47, a74 - ((bef == '7') ? 1 : 0), '4')) { --a4; if (bef == '7') --a74; bef = ans[i] = '4'; continue; }
            if (check(a4, a7 - 1, a47 - ((bef == '4') ? 1 : 0), a74, '7')) { --a7; if (bef == '4') --a47; bef = ans[i] = '7'; continue; }
            goto failed;
        }
        ans[N] = 0;
        puts(ans);
        continue;
    failed:;
//ans[i]=0;cout<<"ans? = "<<ans<<endl;
        puts("-1");
    }
    
    return 0;
}