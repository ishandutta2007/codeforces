#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

string assign(string s, int prev) {
    int unassigned = -1;
    FO(i,0,sz(s)) if (s[i] == '?') {
        unassigned = i;
        break;
    }
    if (unassigned == -1) {
        if (atoi(s.c_str()) <= prev) return "";
        else return s;
    }
    string ns = s;
    FO(i,unassigned+1,sz(ns)) if (ns[i] == '?') ns[i] = '9';
    FO(d,0,10) {
        if (unassigned == 0 && d == 0) continue;
        ns[unassigned] = d + '0';
        if (atoi(ns.c_str()) > prev) {
            s[unassigned] = d+'0';
            return assign(s,prev);
        }
    }
    return "";
}

vector<string> solve(vector<string> v) {
    //printf("slv\n");
    //FO(i,0,sz(v)) printf("%s\n", v[i].c_str());
    //printf("-\n");
    int prev = 0;
    FO(i,0,sz(v)) {
        string x = assign(v[i], prev);
        if (x == "") return vector<string>();
        else {
            v[i] = x;
            prev = atoi(x.c_str());
        }
    }
    return v;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<string> v;
    char buf[10];
    FO(i,0,n) {
        scanf(" %s", buf);
        v.push_back(string(buf));
    }
    int llen = 0;
    FO(i,0,n) if (sz(v[i]) < llen) {
        printf("NO\n");
        return 0;
    } else llen = sz(v[i]);
    llen = 0;
    vector<string> cur;
    vector<string> res;
    FO(i,0,n) if (sz(v[i]) > llen) {
        if (!cur.empty()) {
            cur = solve(cur);
            if (cur.empty()) {
                printf("NO\n");
                return 0;
            }
            FO(i,0,sz(cur)) res.push_back(cur[i]);
        }
        llen = sz(v[i]);
        cur.clear(); cur.push_back(v[i]);
    } else {
        cur.push_back(v[i]);
    }
    if (!cur.empty()) {
        cur = solve(cur);
        if (cur.empty()) {
            printf("NO\n");
            return 0;
        }
        FO(i,0,sz(cur)) res.push_back(cur[i]);
    }
    printf("YES\n");
    FO(i,0,sz(res)) printf("%s\n", res[i].c_str());
}