#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

int main(){
    string s;
    cin >> s;
    int cnt = 0;
    bool ng = false;
    vector<int> res;
    REP(i, s.size()) {
        if(s[i] == '(') {
            cnt++;
        } else if(s[i] == ')') {
            cnt--;
            if(cnt < 0) ng = true;
        } else {
            cnt--;
            if(cnt < 0) ng = true;
            res.push_back(1);
        }
    }
    res[res.size() - 1] += cnt;

    cnt = 0;
    int idx = 0;
    REP(i, s.size()) {
        if(s[i] == '(') {
            cnt++;
        } else if(s[i] == ')') {
            cnt--;
            if(cnt < 0) ng = true;
        } else {
            cnt -= res[idx++];
            if(cnt < 0) ng = true;
        }
    }

    if(ng) {
        cout << -1 << endl;
    } else {
        REP(i, res.size()) {
            cout << res[i] << endl;
        }
    }
    return 0;
}