#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(10);
    for(int i = 1;i < 10;i++){
        cin >> a[i];
    }
    for(int i = 0;i < n;i++){
        if (a[s[i] - '0'] > s[i] - '0'){
            int ii = i;
            while(ii < n){
                if (a[s[ii]-'0'] >= s[ii]-'0'){
                    s[ii] = a[s[ii]-'0'] + '0';
                }
                else{
                    cout << s;
                    return 0;
                }
                ii++;
            }
            cout  << s;
            return 0;
        }
    }
    cout << s;
}