#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
string large(int m, int s) {
    string res = "";
    for(int i = 0; i < m; i++) {
        for(int k = 9; k >= 0; k--) {
            if(s - k >= 0) {
                res += '0' + k;
                s -= k;
                break;
            }
        }
    }
    return res;
}
string small(int m, int s) {
    string res = "";
    for(int i = 0; i < m; i++) {
        for(int k = (i == 0 ? 1 : 0); k <= 9; k++) {
            if(s - k - (m - 1 - i) * 9 <= 0) {
                res += '0' + k;
                s -= k;
                break;
            }
        }
    }
    return res;
}

bool ng(int m, int s) {
    if(9 * m < s) return true;
    if(s == 0 && m > 1) return true;
    return false;
}

int main(){
    int m, s;
    cin >> m >> s;
    if(ng(m, s)) {
        cout << "-1 -1" << endl;
    } else if(m == 1 && s == 0) {
        cout << "0 0" << endl;
    } else {
        string a = small(m, s);
        assert(a.size() == m);
        string b = large(m, s);
        assert(b.size() == m);
        cout << a << " " << b << endl;
    }
    return 0;
}