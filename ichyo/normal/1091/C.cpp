#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
inline bool valid(int x, int w) { return 0 <= x && x < w; }

void iostream_init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
}

LL calc(LL n, LL k) {
    LL len = n / k;
    return len * (1LL + n + 1 - k) / 2;
}

int main(){
    iostream_init();
    int n;
    cin >> n;
    set<LL> answer;
    for (int i = 1; (long long)i * i <= n; i++) {
        if (n % i == 0) {
            answer.insert(calc(n, i));
            if (i * i != n) {
                answer.insert(calc(n, n / i));
            }
        }
    }
    vector<LL> answerlist(answer.begin(), answer.end());
    for(int i = 0; i < answerlist.size(); i++) {
        cout << answerlist[i];
        if(i + 1 < answerlist.size()) {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}