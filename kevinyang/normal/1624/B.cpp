#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int a,b,c;
        cin >> a >> b >> c;
        bool f = false;
        if(true){
            int v = b-(c-b);
            if(v>0&&v%a==0){
                f = true;
            }
        }
        if(true){
            if(a%2==c%2){
                int v = (a+c)/2;
                if(v%b==0){
                    f = true;
                }
            }
        }
        if(true){
            int v = b+(b-a);
            if(v>0&&v%c==0){
                f = true;
            }
        }
        if(f)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}