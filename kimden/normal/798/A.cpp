#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.length();
    int cnt = 0;
    for(int i = 0; i < n / 2; ++i){
        cnt += (s[i] == s[n - 1 - i] ? 0 : 1);
    }
    if((n % 2 == 0 && cnt == 1) || (n % 2 == 1 && cnt <= 1)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}