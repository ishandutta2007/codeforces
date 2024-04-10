#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

vector <pair <int, int>> vec[200005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        int a, b;
        cin >> a >> b;
        vec[a].push_back({b, i});
    }
    vector <int> res;
    set <pair <int, int>> q;
    for(int i=1; i<=200000; i++){
        for(auto c : vec[i]) q.insert(c);
        while(!q.empty() && q.begin()->first < i) q.erase(q.begin());
        while(q.size() > k){
            res.push_back(q.rbegin()->second);
            q.erase(*q.rbegin());
        }
    }
    cout << res.size() << "\n";
    for(auto c : res) cout << c << " ";
    return 0;
}