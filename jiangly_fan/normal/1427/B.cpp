#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> v;
        int cnt = 0, ans = 0, f = 0, d = 0;
        for(char c : s){
            if(c == 'L') cnt += 1;
            else{
                ans += 1;
                if(cnt){
                    if(f) v.push_back(cnt);
                    cnt = 0;
                }
                f = 1;
            }
        }
        if(ans == 0){
            cout << max(0, 2 * k - 1) << "\n";
            continue;
        }
        for(int i = 0; i < n; i += 1) if(s[i] == 'W' and (i == 0 or s[i - 1] == 'L')) d += 1;
        sort(v.begin(), v.end());
        int base = min(n, ans + k) * 2 - d;
        for(int x : v)
            if(k >= x){
                k -= x;
                base += 1;
            }
        cout << base << "\n";
    }
    return 0;
}