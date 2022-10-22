#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin >> n;
    map<char,int> a;
    for(int i =0;i < n;i++){
        string s;
        cin >> s;
        char c = s[0];
        a[c]++;
    }
    int ans = 0;
    for(auto h : a){
        int b = h.second;
        if(b % 2 == 0){
            ans += 2 * ((b / 2) * (b / 2 - 1) / 2);
        }
        else{
            ans += ((b / 2) * (b / 2 - 1) / 2) + ((b / 2 + 1) * (b / 2) / 2);
        }
    }
    cout << ans;


}