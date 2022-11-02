#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include <cstdio>
 
using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> ii;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define mp make_pair
#define pb push_back

const int BUBEN = 11 * 1000 * 1000;

char buf[1005000 * 2];

vector<string> v;

string names[1005000 * 2];
vector<int> ch[1005000 * 2];
int cnt = 0;

vector<string> tokenize() {
    int i = 0;
    vector<string> res;
    while (buf[i]) {
        int j = i + 1;
        string s;
        while (buf[j] != '>') s += buf[j++];
        res.pb(s);
        i = j + 1;
    }
    return res;
}

void parse() {
    vector<string> tokens = tokenize();
    int cur = cnt++;
    vi st;
    
    for (int i = 0; i < sz(tokens); ++i) {
        string s = tokens[i];
        if (s[0] == '/') {
            cur = st[sz(st) - 1];
            st.pop_back();
            continue;
        }
        
        if (s[sz(s) - 1] == '/') {
            int tmp = cnt++;
            names[tmp] = s.substr(0, sz(s) - 1);
            ch[cur].pb(tmp);
            continue;
        }
        
        int tmp = cnt++;
        ch[cur].pb(tmp);
        names[tmp] = s.substr(0, sz(s));
        st.pb(cur);
        cur = tmp;
    }
}

int dfs(int r, int pos = 0) {
    int res = 0;
    if (pos < sz(v) && v[pos] == names[r]) ++pos;
    if (pos >= sz(v) && names[r] == v[sz(v) - 1]) ++res;
    for (int i = 0; i < sz(ch[r]); ++i)
        res += dfs(ch[r][i], pos);
    return res;
}

int main() {
    gets(buf);
    parse();
    
    gets(buf);
    int n;
    sscanf(buf, "%d", &n);
    
    for (int i = 0; i < n; ++i) {
        gets(buf);
        stringstream ss(buf);
        v.clear();
        string s;
        while (ss >> s) v.pb(s);
        
        cout << dfs(0) << "\n";
    }
        return 0;
}