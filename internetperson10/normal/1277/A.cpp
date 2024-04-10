#include <bits/stdc++.h>
using namespace std;

vector<bool> columns;

int main() {
    int t;
    cin >> t;
    while(t--) {
        bool add=false;
        int n, ans=0, latest=10;
        cin >> n;
        while(n) {
            if(n>9) ans+=9;
            else {
                if(n>latest) ans+=(n-1);
                else ans+=n;
            }
            if(n%10>latest && latest!=10) latest=(n%10)-1;
            else latest=n%10;
            n/=10;
        }
        cout << ans << '\n';
    }
}