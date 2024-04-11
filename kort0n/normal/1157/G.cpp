#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int n, m;
int a[202][202];
int now[202][202];
int row[205];
int column[205];
void init() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            now[i][j] = a[i][j];
            row[i] = 0;
            column[j] = 0;
        }
    }
}

bool issorted() {
    bool one = false;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(now[i][j] == 1) one = true;
            if(one && (now[i][j] == 0)) return false;
        }
    }
    return true;
}

void sort1() {
    init();
    for(int j = 1; j <= m; j++) {
        if(now[1][j] == 1) {
            column[j] = 1;
            for(int i = 1; i <= n; i++) now[i][j] = 1 - now[i][j];
        }
    }
    bool one = false;
    for(int i = 2; i <= n; i++) {
        if(one xor (now[i][1] == 1)) {
            row[i] = 1;
            for(int j = 1; j <= m; j++) now[i][j] = 1 - now[i][j];
        }
        for(int j = 1; j <= m; j++) {
            if(now[i][j] == 1) one = true;
        }
    }
}


void sort2() {
    init();
    row[1] = 1;
    for(int j = 1; j <= m; j++) {
        now[1][j] = 1 - now[1][j];
    }
    for(int j = 1; j <= m; j++) {
        if(now[1][j] == 1) {
            column[j] = 1;
            for(int i = 1; i <= n; i++) now[i][j] = 1 - now[i][j];
        }
    }
    bool one = false;
    for(int i = 2; i <= n; i++) {
        if(one xor (now[i][1] == 1)) {
            row[i] = 1;
            for(int j = 1; j <= m; j++) now[i][j] = 1 - now[i][j];
        }
        for(int j = 1; j <= m; j++) {
            if(now[i][j] == 1) one = true;
        }
    }
}

void sort_1(int C) {
    init();
    for(int j = 1; j < C; j++) {
        if(now[1][j] == 1) {
            column[j] = 1;
            for(int i = 1; i <= n; i++) now[i][j] = 1 - now[i][j];
        }
    }
    for(int j = C; j <= m; j++) {
        if(now[1][j] == 0) {
            column[j] = 1;
            for(int i = 1; i <= n; i++) now[i][j] = 1 - now[i][j];
        }
    }
    for(int i = 2; i <= n; i++) {
        if(now[i][1] == 0) {
            row[i] = 1;
            for(int j = 1; j <= m; j++) now[i][j] = 1 - now[i][j];
        }
    }
}

void sort_2(int C) {
    init();
    row[1] = 1;
    for(int j = 1; j <= m; j++) now[1][j] = 1 - now[1][j];
    for(int j = 1; j < C; j++) {
        if(now[1][j] == 1) {
            column[j] = 1;
            for(int i = 1; i <= n; i++) now[i][j] = 1 - now[i][j];
        }
    }
    for(int j = C; j <= m; j++) {
        if(now[1][j] == 0) {
            column[j] = 1;
            for(int i = 1; i <= n; i++) now[i][j] = 1 - now[i][j];
        }
    }
    for(int i = 2; i <= n; i++) {
        if(now[i][1] == 0) {
            row[i] = 1;
            for(int j = 1; j <= m; j++) now[i][j] = 1 - now[i][j];
        }
    }
}

void print() {
    for(int i = 1; i <= n; i++) cout << row[i];
    cout << endl;
    for(int j = 1; j <= m; j++) cout << column[j];
    cout << endl;
    return;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) cin >> a[i][j];
    }
    sort1();
    if(issorted()) {
        cout << "YES" << endl;
        print();
        return 0;
    }
    sort2();
    if(issorted()) {
        cout << "YES" << endl;
        print();
        return 0;
    }
    for(int j = 1; j <= m; j++) {
        cerr << j << endl;
        sort_1(j);
        if(issorted()) {
            cout << "YES" << endl;
            print();
            return 0;
        }
        cerr << j << endl;
        sort_2(j);
        if(issorted()) {
            cout << "YES" << endl;
            print();
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}