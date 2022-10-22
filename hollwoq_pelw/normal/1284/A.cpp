#include <bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cin >> n >> m;
    string f[n];
    string s[m];
    for (int i = 0; i < n; i++) cin >> f[i];
    for (int i = 0; i < m; i++) cin >> s[i];
    int q;
    cin >> q;
    while (q){
        q--;
        long a;
        cin >> a;
        a --;
        cout << f[a%n]+s[a%m] << endl;
    }
    return 0;
    
}