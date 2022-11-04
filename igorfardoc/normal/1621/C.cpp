#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int q(int a) {
    cout << "? " << a + 1 << endl;
    int res;
    cin >> res;
    --res;
    return res;
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
        vi ans(n);
        vector<pair<int, int>> where(n, {-1, -1});
        vvi c;
        int was = 0;
        q(0);
        set<int> s;
        for(int i = 0; i < n; i++) {
            s.insert(i);
        }
        for(int i = 0; i < n; i++) {
            if(i == n - 1) {
                ans[i] = *(s.begin());
                break;
            }
            vi here;
            int end;
            while(true) {
                int rs = q(i);
                ++was;
                if(where[rs].first == -1) {
                    here.push_back(rs);
                    where[rs] = {c.size(), here.size() - 1};
                    if(i == n - 1) {
                        end = rs;
                        ++was;
                        break;
                    }
                } else {
                    end = rs;
                    break;
                }
            }
            c.push_back(here);
            //if(here.size() == 0) {
            int id1 = where[end].first;
            int id2 = where[end].second;
            int sz = c[id1].size();
            if(here.empty()) {
                ans[i] = c[id1][(id2 - (was - 1) % sz + sz) % sz];
            } else {
                ans[i] = c[id1][(id2 - (was - 1) % sz + sz) % sz];
            }
            s.erase(s.find(ans[i]));
            //} else {
        }
        cout << "! ";
        for(const auto& el : ans) {
            cout << el + 1 << ' ';
        }
        cout << endl;
    }

}