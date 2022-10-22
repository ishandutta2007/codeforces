#include <bits/stdc++.h>
using namespace std;


signed main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int i, n, j;
    cin >> n;
    map < char, vector < int > > m;
    string a, b; cin >> a >> b;
    for (i = 0; i < n; i++){
        m[b[i]].push_back(i);
    }
    vector < pair < int, int > > ans;
    for (i = 0; i < n; i++){
        if (a[i] != '?'){
            if (m.find(a[i]) != m.end()){
                ans.push_back({i, m[a[i]].back()});
                m[a[i]].pop_back();
                if (m[a[i]].empty()){
                    m.erase(a[i]);
                }
            }
            else if (m.find('?') != m.end()){
                ans.push_back({i, m['?'].back()});
                m['?'].pop_back();
                if (m['?'].empty()){
                    m.erase('?');
                }
            }
        }
    }
    for (i = 0; i < n; i++){
        if (a[i] == '?'){
            if (!m.empty()){
                char cur = (*m.begin()).first;
                ans.push_back({i, m[cur].back()});
                m[cur].pop_back();
                if (m[cur].empty()){
                    m.erase(cur);
                }
            }
        }
    }
    cout << ans.size() << endl;
    for (auto cur : ans){
        cout << cur.first + 1 << " " << cur.second + 1 << endl;
    }

    return 0;
}