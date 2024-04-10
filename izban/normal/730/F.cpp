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
const int N = 5555 + 10;
const long long INF = 1e9 + 19;


int n, B;
int a[N];
int b[N];
int add[N];
int can[N];

void read() {
    scanf("%d%d", &n, &B);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

bool isGood() {
    int curB = B;
    for (int i = 0; i < n; i++) {
        assert(b[i] * 2 <= a[i]);
        if (curB < b[i])
            return 0;
        curB -= b[i];
        curB += (a[i] - b[i]) / 10;
    }
    return 1;
}


void build() {
    for (int i = n - 1; i >= 0; i--) {
        //db2(i, "main");
        b[i] += add[i];
        if (!isGood()) {
            //db(i);
            b[i] -= add[i];
            for (int j = 1; ;j++) {
                b[i]++;
                if (!isGood()) {
                    b[i]--;
                    break;
                }
            }
            break;
        }
    }
    /*for (int i = 0; i < n; i++)
        cerr << b[i] << " ";
    cerr << endl;
    for (int i = 0; i < n; i++)
        cerr << can[i] << " ";
    cerr << endl;*/

    for (int val = 10; val >= 1; val--) {
        for (int i = n - 1; i >= 0; i--) {
            bool fail = 0;
            while (true) {
                int rem = can[i] - b[i];
                if (rem >= val) {
                    b[i] += val;
                    if (!isGood()) {
                        b[i] -= val;
                        fail = 1;
                        break;
                    }
                }
                else
                    break;
            }
            if (val < 10 && fail) {
                break; 
            }
        }
    }
}

int solve() {
    for (int i = 0; i < n; i++)
        b[i] = 0;
    for (int i = 0; i < n; i++)
        can[i] = a[i] / 2;
         
    for (int i = 0; i < n; i++)
        add[i] = min(can[i], a[i] % 10);
    add[n - 1] = can[n - 1];

    build();

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i] - b[i];

    assert(isGood());
    printf("%d\n", sum);
    for (int i = 0; i < n; i++)
        printf("%d ", b[i]);
    puts("");
    return sum;
}

void genTest() {    
    n = 5000; 
    int T = 40;
    B = rand() % T;
    for (int i = 0; i < n; i++)
        a[i] = rand() % T + 1;
}



int stupid() {
    //memset(dp, 63, sizeof(dp));
    int mx = B;
    for (int i = 0; i < n; i++)
        mx += a[i];
    vector<vector<int>> dp(n + 1, vector<int>(mx + 1, INF));
    dp[0][B] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= mx; j++) {
            if (dp[i][j] < INF) {
                //db(a[i]);
                for (int k = 0; k <= min(j, a[i] / 2); k++) {
                    int newB = j - k + (a[i] - k) / 10;
                    //db(newB);
                    dp[i + 1][newB] = min(dp[i + 1][newB], dp[i][j] + a[i] - k);
                }
            }
        }
    }
    /*for (int i = 0; i <= n; i++, cerr << endl)
        for (int j = 0; j <= 20; j++)
            cerr << dp[i][j] << " ";*/


    int answer = INF;
    for (int k = 0; k <= mx; k++)
        answer = min(answer, dp[n][k]);

    return answer;
}

void printTest() {
    cout << n << " " << B << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void stress() {
    for (int tt = 0; ; tt++) {
        db(tt);
        genTest();
        printTest();
        exit(0);
        int r1 = solve();
        int r2 = stupid();
        if (r1 != r2) {
            db2(r1, r2);
       }
        assert(r1 == r2);
    }

}


int main(){
#ifdef MY_DEBUG
    freopen("in", "r", stdin);
    //freopen("test.txt", "w", stdout);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
            //cout << stupid() << endl;
        }
    }
    else {
        stress();
    }

    return 0;
}