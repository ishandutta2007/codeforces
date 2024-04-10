#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int get2(string& s, int l) {
    return (int)(s[l] - '0') * 10 + (s[l + 1] - '0');
}

int get3(string& s, int l) {
    return (int)(s[l] - '0') * 100 + (int)(s[l + 1] - '0') * 10 + (int)(s[l + 2] - '0');
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
        int n, m;
        cin >> n >> m;
        vector<array<int, 3>> here2(2000, {-1, -1, -1});
        vector<array<int, 3>> here3(2000, {-1, -1, -1});
        for(int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for(int j = 0; j < m - 1; j++) {
                here2[get2(s, j)] = {j, j + 1, i};
                if(j != m - 2) {
                    here3[get3(s, j)] = {j, j + 2, i};
                }
            }
        }
        string s;
        cin >> s;
        vi b;
        b.push_back(-1);
        for(int i = 0; i < m - 1; i++) {
            int h = get2(s, i);
            if(here2[h][0] == -1) {
                b.push_back(i);
            }
        }
        b.push_back(m - 1);
        vector<array<int, 3>> ans;
        bool ok = true;
        for(int o = 0; o < b.size() - 1; o++) {
            int l = b[o] + 1;
            int r = b[o + 1];
            if((r - l + 1) % 2 == 0) {
                for(int i = l; i <= r; i+=2) {
                    int h = get2(s, i);
                    ans.push_back(here2[h]);
                }
            } else {
                bool okhere = false;
                int i = l;
                while(i <= r) {
                    if(r - i <= 1 && !okhere) break;
                    int h2 = get2(s, i);
                    if(okhere) {
                        ans.push_back(here2[h2]);
                        i += 2;
                        continue;
                    }
                    int h3 = get3(s, i);
                    if(here3[h3][0] != -1) {
                        okhere = true;
                        ans.push_back(here3[h3]);
                        i += 3;
                        continue;
                    }
                    ans.push_back(here2[h2]);
                    i += 2;
                }
                if(!okhere) {
                    ok = false;
                    break;
                }
            }
        }
        if(!ok) {
            cout << -1 << '\n';
            continue;
        }
        cout << ans.size() << '\n';
        for(const auto& el : ans) {
            cout << el[0] + 1 << ' ' << el[1] + 1 << ' ' << el[2] + 1 << '\n';
        }
    }
}