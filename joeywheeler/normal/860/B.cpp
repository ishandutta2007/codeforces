#include <bits/stdc++.h>

#define fo(i,a,b) for (int i=(a); i<(b); i++)
#define sz(v) int(v.size())

using namespace std;

vector<pair<string,int> > v;
string bst[70005];

bool good(string t, string s) {
    if (sz(s) < sz(t)) return true;
    return s.substr(0,sz(t)) != t;
}

void updb(int i, string u) {
    if (sz(bst[i]) == 0 || sz(u) < sz(bst[i])) bst[i] = u;
}

int main() {
    int n; scanf("%d ", &n);
    fo(i,0,n) {
        string s;
        cin >> s;
        fo(j,0,9) {
            string suff = s.substr(j);
            v.emplace_back(suff, i);
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < sz(v); ) {
        int j = i;
        for (;j < sz(v) && v[j].second == v[i].second; j++) {
        }

        fo(k,i,j) {
            fo(l,1,sz(v[k].first)+1) {
                string t = v[k].first.substr(0,l);
                bool bad = false;
                if (i && !good(t, v[i-1].first)) bad = true;
                if (j < sz(v) && !good(t, v[j].first)) bad = true;
                if (!bad) {
                    updb(v[k].second, t);
                    break;
                }
            }
        }

        i = j;
    }

    fo(i,0,n) printf("%s\n", bst[i].c_str());
}