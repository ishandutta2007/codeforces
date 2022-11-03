#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    string s;
    cin >> s;
    int n = s.length();
    map<char, int> mp;
    for(int i = 0; i < n; ++i){
        ++mp[s[i]];
    }
    int k = n / 2;
    set<string> ans;
    if(mp['1'] < n - k){
        ans.insert("00");
    }
    if(mp['0'] < k){
        ans.insert("11");
    }
    if(mp['0'] <= k && mp['1'] <= n - k){
        if(s.back() == '1' || (s.back() == '?' && mp['1'] < n - k)){
            ans.insert("01");
        }
        if(s.back() == '0' || (s.back() == '?' && mp['0'] < k)){
            ans.insert("10");
        }
    }
    for(auto p: ans){
        cout << p << endl;
    }



}