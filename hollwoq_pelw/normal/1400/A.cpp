#include<bits/stdc++.h>
using namespace std;
int main(){
    int t, n;
    string s;
    cin >> t;
    while(t--){
        cin >> n >> s;
        for (int i = 0; i < n; i++)
            cout << s[n - 1];
        cout << endl;
    }
}