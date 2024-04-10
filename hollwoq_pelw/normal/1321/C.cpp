#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin >> n >> s;
    bool mrk[n] = {0};
    for (int i = 0; i < n; i++){
        if (i > 0){
            int x = i;
            do{
                x --;
                if (s[i] - s[x] == 1) mrk[i] = 1;
                if (s[i] - s[x] == -1) mrk[x] = 1;
            } while(mrk[x]);
        }
    }
    int ans = 0;
    for (auto a: mrk) ans += a;
    cout << ans;
    return 0;
}