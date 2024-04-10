#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false);
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    for(int j = 0; j < t; j++){
        for(int i = 0; i + 1 < n; i++){
            if(s[i] == 'B' && s[i + 1] == 'G'){
                swap(s[i], s[i + 1]);
                i++;
            }
        }
    }
    cout << s;
    return 0;
}