#include <bits/stdc++.h>
using namespace std;
int cnt[7];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < 7; j++) {
            if(s[j] == '1') cnt[j]++;
        }
    }
    int mx = 0;
    for(int i = 0; i < 7; i++){
        mx = max(mx, cnt[i]);
    }
    cout << mx << endl;
    return 0;
}