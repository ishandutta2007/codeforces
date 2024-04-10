#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n == 1){
        if(s[0] == '1') cout << "Yes";
        else cout << "No";
        return 0;
    }
    for(int i=1; i<n; i++) if(s[i] == '1' && s[i-1] == '1'){cout << "No"; return 0;}
    if(s[0] == '0' && s[1] == '0'){cout << "No"; return 0;}
    if(s[n-1] == '0' && s[n-2] == '0'){cout << "No"; return 0;}
    for(int i=1; i<n-1; i++){
        if(s[i] == '0' && s[i-1] == '0' && s[i-2] == '0'){cout << "No"; return 0;}
    }
    cout << "Yes";

    return 0;
}