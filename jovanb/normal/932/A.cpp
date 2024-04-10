#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    string str;
    cin >> str;
    int n=str.size();
    for(int i=0; i<n; i++) cout << str[i];
    for(int i=n-1; i>=0; i--) cout << str[i];
    return 0;
}