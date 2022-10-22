#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    int x = n;
    string str;
    cin >> str;
    for(int i=0; i<n-1; i++){
        if(str[i] != str[i+1]){i++; x --;}
    }
    cout << x;
    return 0;
}