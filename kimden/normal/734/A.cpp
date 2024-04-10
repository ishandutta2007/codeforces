#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); ++i){
        if(s[i] == 'A'){
            n -= 2;
        }
    }
    if(n > 0){
        cout << "Danik" << endl;
    }else{
        if(n < 0){
            cout << "Anton" << endl;
        }else{
            cout << "Friendship" << endl;
        }
    }
    return 0;
}