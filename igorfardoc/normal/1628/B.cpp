#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

bool get1(string s) {
    int n = s.size();
    for(int i = 0; i < n; i++) {
        if(s[i] != s[n - 1 - i]) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        bool ok = false;
        set<string> two;
        set<string> three;
        set<string> three2;
        for(int i = 0; i < n; i++) {
            string s;
            cin >> s;
            if(get1(s)) {
                ok = true;
            }
            if(s.size() == 2) {
                string need2 = s;
                reverse(need2.begin(), need2.end());
                if(two.find(need2) != two.end()) {
                    ok = true;
                }
                if(three2.find(need2) != three2.end()) {
                    ok = true;
                }
                two.insert(s);
            } else if(s.size() == 3) {
                string rev = s;
                reverse(rev.begin(), rev.end());
                if(three.find(rev) != three.end()) {
                    ok = true;
                }
                string need2 = "";
                need2 += s[2];
                need2 += s[1];
                if(two.find(need2) != two.end()) {
                    ok = true;
                }
                three.insert(s);
                string t = "";
                t += s[0];
                t += s[1];
                three2.insert(t);
            }
        }
        if(ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }
}