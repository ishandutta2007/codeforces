#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;


ll pw(ll p, ll q){
    ll ret = 1;
    for (; q; q >>= 1){
        if (q & 1)
            ret = ret * p % MM;
        p = p * p % MM;
    }
    return ret;
}

string s;
map<string, int> mp1;
map<string, string> mp2;

void solve(int casi){
    //printf("Case #%d:", casi);
    int n, Q;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> s;
        int m = s.length();
        vector<string> ss;
        for (int p = 0; p < m; p++){
            string t = "";
            for (int q = p; q < m; q++){
                t.push_back(s[q]);
                ss.push_back(t);
            }
        }
        sort(ss.begin(), ss.end());
        ss.resize(unique(ss.begin(), ss.end()) - ss.begin());
        for (auto &x : ss){
            mp1[x]++;
            mp2[x] = s;
        }
    }
    cin >> Q;
    for (int i = 1; i <= Q; i++){
        cin >> s;
        auto maki = mp1.find(s);
        if (maki == mp1.end())
            cout << "0 -" << endl;
        else {
            cout << maki->second << ' ' << mp2[s] << endl;
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    solve(0);
    return 0;
}