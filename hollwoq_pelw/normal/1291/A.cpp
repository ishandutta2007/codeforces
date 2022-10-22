#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t){
        t--;
        int n,codd=0;
        string s;
        cin >> n >> s;
        int a[2],k;
        for (int i = 0; i < n; i++){
            k = s[i]-'0';
            if (k%2!=0){
                if (codd < 2){
                    a[codd] = k;
                }
                codd++;
            }
        }
        if (codd < 2) cout << -1 << endl;
        else cout << a[0] << a[1] << endl;
    }
    return 0;
}