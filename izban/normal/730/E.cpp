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
#define sz(a) (int)(a).size()

#define equal equalll
#define less lesss
typedef long long ll;
const int N = 111;
const long long INF = 1e9 + 19;

struct Per {
    int a, id, d;
};

int n;
Per per[N];

bool cmp(pair<int,int> A, pair<int,int> B) {
    return A.fr > B.fr || (A.fr == B.fr && A.sc < B.sc);
}

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &per[i].a);
        scanf("%d", &per[i].d);
        per[i].id = i;
    }

    for (int i = 0; i < n; i++)
    sort(per, per + n, [](Per A, Per B) {
            return cmp(mp(A.a, A.id), mp(B.a, B.id));
            });

    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            auto ri = mp(per[i].a + per[i].d, per[i].id);
            auto rj = mp(per[j].a + per[j].d, per[j].id);
            auto bi = mp(per[i].a, per[i].id);
            auto bj = mp(per[j].a, per[j].id);

            if (cmp(rj, ri)) {
                //db("tut");
                answer++;
            }
            else {
                if (cmp(rj, bi))
                    answer += 2;
                if (cmp(bj, ri))
                    answer += 2;
            }
        }
    }
    cout << answer << endl;

}



void solve() {

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