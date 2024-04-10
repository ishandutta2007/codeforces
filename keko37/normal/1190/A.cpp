#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

typedef long long llint;

llint n, m, k, sol, ofs;
deque <llint> dq;

void makni () {
    llint val = dq.front() - ofs;
    llint sk = val / k;
    llint br = 0;
    while (!dq.empty()) {
        llint curr = dq.front() - ofs;
        if (curr / k == sk) dq.pop_front(); else break;
        br++;
    }
    ofs += br;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i=0; i<m; i++) {
        llint x;
        cin >> x; x--;
        dq.push_back(x);
    }
    while (!dq.empty()) {
        sol++;
        makni();
    }
    cout << sol;
    return 0;
}