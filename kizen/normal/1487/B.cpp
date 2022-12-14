#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int s = 1;
        if(n % 2 == 1){
            s += (k - 1) / (n / 2);
        }
        s += k - 1;
        s = (s - 1) % n + 1;
        cout << s << '\n';
    }
    return 0;
}