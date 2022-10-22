#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    string s;
    cin >> s;
    int mn = 0, mx = 0;
    for(int i=0; i<n/2; i++){
        if(s[i] == '?'){
            mx += 9;
        }
        else{
            mn += s[i]-'0';
            mx += s[i]-'0';
        }
    }
    for(int i=n/2; i<n; i++){
        if(s[i] == '?'){
            mn -= 9;
        }
        else{
            mn -= s[i]-'0';
            mx -= s[i]-'0';
        }
    }
    if(mn+mx){
        cout << "Monocarp\n";
    }
    else cout << "Bicarp\n";
    return 0;
}