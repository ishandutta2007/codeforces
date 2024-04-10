#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, d;
    cin >> n >> d;
    vector <pair <int, int>> good, bad;
    for(int i=1; i<=n; i++){
        int s, p;
        cin >> s >> p;
        if(s < d) continue;
        if(s >= p) good.push_back({s, p});
        else bad.push_back({s, p});
    }
    sort(good.begin(), good.end());
    sort(bad.begin(), bad.end(), [](pair <int, int> a, pair <int, int> b){ return a.second < b.second; });
    int neat = 0;
    int taken = 0;
    int i = 0;
    for(int j=0; j<bad.size(); j++){
        if(bad[j].first < neat) continue;
        while(i < good.size() && good[i].first < bad[j].second){
            neat = max(neat, good[i].second);
            i++;
        }
        if(bad[j].first >= neat){
            neat = max(neat, bad[j].second);
            taken++;
        }
    }
    cout << good.size() + taken << "\n";
    return 0;
}