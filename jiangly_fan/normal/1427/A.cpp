#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        vector<int> v;
        int sum = 0, cnt = 0;
        for(int i = 0, x; i < n; i += 1){
            cin >> x;
            sum += x;
            if(not x) cnt += 1;
            else v.push_back(x);
        }
        if(sum == 0)
            cout << "NO\n";
        else{
            sort(v.begin(), v.end());
            cout << "YES\n";
            if(sum > 0) reverse(v.begin(), v.end());
            for(int x : v) cout << x << " ";
            for(int i = 0; i < cnt; i += 1) cout << "0 ";
            cout << "\n";
        }
    }
    return 0;
}