#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;
ll MOD[2] = {1000000009ll, 1000000007ll};
ll BASE[2] = {137ll,137ll};

struct hsh {

    ll val[2];

    bool operator<(const hsh &o) const {
        FO(i,0,2) if (val[i] != o.val[i]) return val[i] < o.val[i];
        return false;
    }
};

hsh add(hsh a, int x) {
    FO(i,0,2) a.val[i] = (a.val[i]*BASE[i]+x)%MOD[i];
    return a;
}


pair<string,string> extract(string s) {
    auto i = s.find("/", 7);
    if (i == string::npos) {
        i = sz(s);
    }
    return make_pair(s.substr(0,i), s.substr(i,sz(s)-i));
}

pair<string,string> m[100005];
string dom[100005];
pair<hsh,int> hs[100005];

int main() {
    int n; scanf("%d ", &n);
    FO(i,0,n) {
        string s;
        getline(cin,s);
        auto p = extract(s);
        m[i] = p;
    }
    sort(m,m+n);
    int g = 0;
    for (int i = 0; i < n;) {
        int j;
        for (j = i; j < n && m[j].first == m[i].first; j++);
        int k = unique(m+i, m+j)-m;
        hsh tmp; tmp.val[0] = tmp.val[1] = 0;
        FO(t,i,k) {
            for (auto c : m[t].second) tmp = add(tmp,c);
            tmp = add(tmp,'?');
        }
        dom[g] = m[i].first;
        hs[g] = make_pair(tmp,g);
        g++;
        i = j;
    }
    sort(hs,hs+g);
    vector<vector<string> > res;
    for (int i = 0; i < g;) {
        int j;
        for (j = i; j < g && !(hs[i].first<hs[j].first) && !(hs[j].first<hs[i].first); j++);
        if (j-i > 1) {
            vector<string> t;
            FO(k,i,j) t.push_back(dom[hs[k].second]);
            res.push_back(t);
        }
        i = j;
    }
    printf("%d\n", sz(res));
    for (auto v : res) {
        FO(i,0,sz(v)) printf("%s%c", v[i].c_str(), " \n"[i+1==sz(v)]);
    }
}