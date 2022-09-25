#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 5555; 
const long long INF = 1e9 + 19;

int a[N];
int cnt[N];
int answer[N];
int n;

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void solve() {

    for (int i = 0; i < n; i++) {
        pair < int, int > best = mp(0, 0);
        memset(cnt, 0, sizeof(cnt));
        for (int j = i; j < n; j++) {
            cnt[a[j]]++; 
            pair < int, int > tmp = mp(cnt[a[j]], a[j]);
            if (tmp.fr > best.fr || (tmp.fr == best.fr && tmp.sc < best.sc))
                best = tmp;
            answer[best.sc]++;
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", answer[i]);
    puts("");


}

void stress() {

}


int main(){
#ifdef MY_DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}