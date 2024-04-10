#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define getTime() cerr << (clock() * 1.0 / CLOCKS_PER_SEC) << endl
#define equal equalll
#define less lesss
const int N = -1;
const int INF = 1e9;

int n;
map < string, int > q;

void toLowerCase(string & s) {
    for (auto& ch: s)
        if ('A' <= ch && ch <= 'Z') {
            ch -= 'A';
            ch += 'a';
        }
}

void read() {
    scanf("%d", &n);
    q["polycarp"] = 1;
    for (int i = 0; i < n; i++) {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        toLowerCase(s1);
        toLowerCase(s3);
        q[s1] = q[s3] + 1;
    }
    int mx = 0;
    for (auto pr: q)
        mx = max(pr.sc, mx);
    printf("%d\n", mx);
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