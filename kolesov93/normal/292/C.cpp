#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <deque>
#include <string>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include <set>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acos(-1.);

using namespace std;

vector<string> cands;
vector<int> can;

vector<string> ans;

char w[11];
bool cused[11];

bool haveAll(const string& w) {
    int l = w.size();
    memset(cused, 0, sizeof(cused));
    for (int i = 0; i < l; ++i) cused[ w[i] - '0' ] = true;
        
    for (int i = 0; i < can.size(); ++i) 
        if (!cused[ can[i] ]) {
            return false;
        }
    return true;
}

void rec(int l) {
    if (l > 6) return;
    if (l >= 2 && l <= 6) {
        string cur = w;
        string rcur = w;
        reverse(rcur.begin(), rcur.end());
        string c1 = cur + rcur;
        string c2 = cur + rcur.substr(1);
        if (haveAll(c1)) cands.push_back(c1);
        if (haveAll(c2)) cands.push_back(c2);
    }

    for (int i = 0; i < can.size(); ++i) {
        w[l] = '0' + can[i];
        rec(l + 1);
    }
    w[l] = 0;
}

string cans[4];
string cur;
int used;

bool cool(string s) {
    if (s.size() == 0 || s.size() > 3) return false;
    if (s[0] == '0') {
        return s.size() == 1;
    }
    int c = 0;
    for (int i = 0; i < s.size(); ++i) {
        c = c * 10 + s[i] - '0';
    }
    return c < 256; 
}

void rec2(int l) {
    if (l == 4) {
        ans.push_back(cans[0] + "." + cans[1] + "." + cans[2] + "." + cans[3]);
        return;
    }

    if (l == 3) {
        if (cur.size() - used > 0 && cur.size() - used < 4) {
            string nc = cur.substr(used);
            if (cool(nc)) {
                cans[3] = nc;
                rec2(4);
            }
        }
        return;
    }

    if (cur.size() - used <= 0) return;
    for (int i = 1; i <= 3 && used + i <= cur.size(); ++i) {
        cans[l] = cur.substr(used, i);
        if (cool(cans[l])) {
            used += i;
            rec2(l + 1);
            used -= i;
        }
    }
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n;
    cin >> n;

    while (n--) {
        int x; cin >> x;
        can.push_back(x);
    }

    rec(0); 

    for (int i = 0; i < cands.size(); ++i) {
        used = 0;
        cur = cands[i];
        rec2(0);
    }

    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        puts(ans[i].c_str());
    }

    return 0;
}