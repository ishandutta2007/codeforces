#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    for(int i = 0; i <s.length(); i++){
        if(s[i] == t[i]){
            cout << "0";
        }else{
            cout <<"1";
        }
    }
    return 0;
}