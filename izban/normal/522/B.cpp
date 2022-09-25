#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define getTime() cerr << (clock() * 1.0 / CLOCKS_PER_SEC) << endl
#define equal equalll
#define less lesss
const int N = 1e6;
const int INF = 1e9;

int n;
int w[N];
int h[N];

void read() {
    scanf("%d", &n);
    int sumW = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &w[i], &h[i]);
        sumW += w[i];
    }
    int mx1 = -1;
    int mx2 = -1;
    for (int i = 0; i < n; i++)
        if (mx2 == -1 || h[i] > h[mx2]) {
            mx2 = i; 
            if (mx1 == -1 || h[mx1] < h[mx2])
                swap(mx1, mx2);
        }
    //cerr << "mx1 mx2: " << mx1 << " " << mx2 << endl;
    for (int i = 0; i < n; i++) {
        int pos = (i == mx1)? mx2: mx1;
        printf("%lld ", (sumW - w[i]) * 1ll * h[pos]);
    }
    printf("\n");
}

void solve() {

}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        while (true) {
            read();
            solve();
            printAns();
            return 0;
        }
    }
    else {
        stress();
    }

    return 0;
}