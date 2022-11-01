#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, m, p;
char s[500005];
int o[500005];
vector<int> stk;
char q[500005];

int main() {
    scanf("%d%d%d", &n, &m, &p);
    scanf(" %s", s);
    FO(i,0,n) if (s[i] == '(') {
        stk.push_back(i);
    } else {
        o[stk.back()] = i;
        o[i] = stk.back();
        stk.pop_back();
    }
    set<int> l;
    FO(i,0,n) l.insert(i);
    p--;
    scanf(" %s", q);
    FO(z,0,m) {
        char t = q[z];
        if (t == 'L') {
            p = *--l.find(p);
        } else if (t == 'R') {
            p = *++l.find(p);
        } else {
            int q = o[p];
            if (q < p) swap(p,q);
            while (1) {
                auto it = l.lower_bound(p);
                if (it == l.end() || *it > q) break;
                l.erase(it);
            }
            auto it = l.lower_bound(p);
            if (it == l.end()) --it;
            p = *it;
        }
    }
    for (int i : l) printf("%c", s[i]);
    printf("\n");
}