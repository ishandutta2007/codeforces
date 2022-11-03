#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

bool a[1000];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string s, t;
    cin >> s;
    int ans = 1;
    for(int i = 1; i < n; i++){
        cin >> t;
        if(s!=t){
            ans++;
        }
        s = t;
    }
    cout << ans;
    return 0;
}