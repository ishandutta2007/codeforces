#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using ull = unsigned long long;

int lp[100002];

int main(){
    int n;
    cin >> n;
    vector<int> pr;
    map<int, int> mp;
    for(int i = 2; i < 100001; i++){
        if(!lp[i]){
            pr.push_back(i);
            lp[i] = i;
        }
        for(int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] < 100001; j++){
            lp[i * pr[j]] = pr[j];
        }
    }
    int last;
    int cur;
    int a;
    for(int i = 0; i < n; i++){
        last = -1;
        cin >> a;
        while(a > 1){
            cur = lp[a];
            a /= cur;
            if(last != cur){
                last = cur;
                mp[cur]++;
            }
        }
    }
    int ans = 1;
    for(auto p: mp){
        ans = max(ans, p.second);
    }
    cout << ans << endl;

    return 0;
}