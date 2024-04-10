#include<bits/stdc++.h>
using namespace std;
using LL = long long;
string f(string s){
    int n = s.size();
    vector<int> d1(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    vector<int> d2(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k ;
        }
    }
    string res[4];
    for(int i = 0; i < n; i += 1) if(i + d1[i] >= n){
        res[0] = s.substr(i - d1[i] + 1);
        break;
    }
    for(int i = 1; i < n; i += 1) if(i + d2[i] >= n){
        res[1] = s.substr(i - d2[i]);
        break;
    }
    for(int i = n - 1; i >= 0; i -= 1) if(i - d1[i] < 0){
        res[2] = s.substr(0, i + d1[i]);
        break;
    }
    for(int i = n - 1; i >= 1; i -= 1) if(i - d2[i] <= 0){
        res[3] = s.substr(0, i + d2[i]);
        break;
    }
    int i = 0;
    for(int j = 1; j < 4; j += 1) if(res[j].size() > res[i].size()) i = j;
    return res[i];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        string s;
        cin >> s;
        int n = s.size();
        int l = 0, r = n - 1;
        while(l < r and s[l] == s[r]){
            l += 1;
            r -= 1;
        }
        if(l >= r) cout << s << "\n";
        else cout << s.substr(0, l) << f(s.substr(l, r - l + 1)) << s.substr(r + 1) << "\n";
    }
    return 0;
}