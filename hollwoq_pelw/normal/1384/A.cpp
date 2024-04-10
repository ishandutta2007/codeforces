#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t; while(t--){
        string s(200, 'a');
        cout << s << endl;
        int n; cin >> n;
        for (int i = 0; i < n; i++){
            int a; cin >> a;
            s[a] = s[a] == 'a' ? 'b' : 'a';
            cout << s << endl;
        }
    }
}