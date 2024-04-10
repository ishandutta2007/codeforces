#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        int l = 0, r = 0;
        for (int i = 0; i < n; i++) if (s[i] == '>'){l = i; break;}
        for (int i = 0; i < n; i++) if (s[n-i-1] == '<'){r = i; break;}
        cout << min(l, r) << endl;
    }
}