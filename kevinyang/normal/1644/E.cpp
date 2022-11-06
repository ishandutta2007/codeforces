#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a = 1; int b = 1; int c = 1; int d = 1;
        string s;
        cin >> s;
        int ex = n-1; int ey = n-1;
        int cx = 0; int cy = 0;
        for(int i = 0; i<s.length(); i++){
            if(s[i]=='D'){
                ex--;
                cx++;
            }
            else{
                ey--;
                cy++;
            }
        }
        int ans = 0;
        if(s[0]=='D'){
            int when = 0;
            for(int i = 0; i<=s.length(); i++){
                if(s[i]=='R'){
                    when = i;
                    break;
                }
            }
            if(when==0){
                cout << n << "\n";
                continue;
            }
            ans = ex*(cy+1)+(n-when)*ey;
        }
        else{
            int when = 0;
            for(int i = 0; i<=s.length(); i++){
                if(s[i]=='D'){
                    when = i;
                    break;
                }
            }
            if(when==0){
                cout << n << "\n";
                continue;
            }
            ans = ey*(cx+1)+(n-when)*ex;
        }
        cout << ans+s.length()+1 << "\n";
    }
    return 0;
}