#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    string s;
    cin >> s;
    int r = 0;
    for(auto c : s){
        if(c == 'A') r++;
        else r--;
    }
    if(r > 0){
        cout << "Anton";
    }
    else if(r == 0){
        cout << "Friendship";
    }
    else cout << "Danik";
    return 0;
}