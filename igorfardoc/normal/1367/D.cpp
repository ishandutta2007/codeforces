#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



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
        string s;
        cin >> s;
        int n = s.size();
        vi am1(26, 0);
        for(int i = 0; i < n; i++) {
            am1[s[i] - 'a']++;
        }
        int m;
        cin >> m;
        vi a(m);
        for(int i = 0; i < m; i++) {
            cin >> a[i];
        }
        vi id1(m, -1);
        int now = 25;
        vi am(26);
        while(true) {
            auto anew = a;
            for(int i = 0; i < m; i++) {
                if(id1[i] == -1 && a[i] == 0) {
                    id1[i] = now;
                    //cout << i << endl;
                    am[now]++;
                    for(int j = 0; j < m; j++) {
                        if(j != i && id1[j] == -1 && a[j] != 0) {
                            anew[j] -= abs(i - j);
                        }
                    }
                }
            }
            a = anew;
            --now;
            bool ok1 = true;
            for(int i = 0; i < m; i++) {
                if(id1[i] == -1) {
                    ok1 = false;
                }
            }
            if(ok1) {
                break;
            }
        }
        //cout << "End loop" << endl;
        int now1 = 0;
        unordered_map<int, char> d;
        for(int i = 0; i < 26; i++) {
            if(am[i] == 0) {
                continue;
            }
            while(am[i] > am1[now1]) {
                ++now1;
            }
            d[i] = (char)(now1 + 'a');
            ++now1;
        }
        for(int i = 0; i < m; i++) {
            cout << d[id1[i]];
        }
        cout << '\n';
    }
}