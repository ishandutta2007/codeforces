#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int x = -1,y = -1;
        for (int i = 0; i < n; i ++){
            if (s[i] == '1'){
                x = i;
                break;
            }
        }
        for (int i = 0; i < n; i ++){
            if (s[n-1-i] == '1'){
                y = i;
                break;
            }
        }
        //cout << x << ' ' << y << endl;
        if (x == -1) cout << n << endl;
        else cout << (n-min(x,y))*2 << endl;
    }
    return 0;
}