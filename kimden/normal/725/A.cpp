#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '>'){
            break;
        }
        ans++;
    }
    for(int i = n - 1; i >= 0; i--){
        if(s[i] == '<'){
            break;
        }
        ans++;
    }
    cout << ans;
    return 0;
}