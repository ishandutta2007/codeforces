#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    string s;
    int ans = 0;
    cout << 2 << endl;
    cin >> s;
    if(s[0]=='y'){
        ans++;
    }
    cout << 3 << endl;
    cin >> s;
    if(s[0]=='y'){
        ans++;
    }
    cout << 5 << endl;
    cin >> s;
    if(s[0]=='y'){
        ans++;
    }
    cout << 7 << endl;
    cin >> s;
    if(s[0]=='y'){
        ans++;
    }
    cout << 4 << endl;
    cin >> s;
    if(s[0]=='y'){
        ans++;
    }
    cout << 9 << endl;
    cin >> s;
    if(s[0]=='y'){
        ans++;
    }
    cout << 25 << endl;
    cin >> s;
    if(s[0]=='y'){
        ans++;
    }
    cout << 49 << endl;
    cin >> s;
    if(s[0]=='y'){
        ans++;
    }

    if(ans == 0){
        cout << "prime";
        return 0;
    }
    if(ans > 1){
        cout << "composite";
        return 0;
    }
    ans = 0;
    cout << 11 << endl;
    cin >> s;
    if(s[0]=='y'){
        ans++;
    }
    cout << 13 << endl;
    cin >> s;
    if(s[0]=='y'){
        ans++;
    }
    cout << 17 << endl;
    cin >> s;
    if(s[0]=='y'){
        ans++;
    }
    cout << 19 << endl;
    cin >> s;
    if(s[0]=='y'){
        ans++;
    }
    cout << 23 << endl;
    cin >> s;
    if(s[0]=='y'){
        ans++;
    }
    cout << 29 << endl;
    cin >> s;
    if(s[0]=='y'){
        ans++;
    }
    cout << 31 << endl;
    cin >> s;
    if(s[0]=='y'){
        ans++;
    }
    cout << 37 << endl;
    cin >> s;
    if(s[0]=='y'){
        ans++;
    }
    cout << 41 << endl;
    cin >> s;
    if(s[0]=='y'){
        ans++;
    }
    cout << 43 << endl;
    cin >> s;
    if(s[0]=='y'){
        ans++;
    }
    cout << 47 << endl;
    cin >> s;
    if(s[0]=='y'){
        ans++;
    }
    if(ans == 0){
        cout << "prime";
    }
    else{
        cout << "composite";
    }
}