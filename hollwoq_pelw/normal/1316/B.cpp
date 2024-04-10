#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, t;
    string s;
    cin >> t;
    while(t--){
        cin >> n >> s;
        string r = s, c = s;
        int m = 1;
        for (int k = 1; k <= n; k++){
            c = s.substr(0,k-1);
            if ((n-k) % 2 == 0) reverse(c.begin(), c.end());
            c = s.substr(k-1)+c;
            //cout << c << endl;
            if (r > c) {m = k; r = c;}
        }
        cout << r << endl << m << endl;
    }
}