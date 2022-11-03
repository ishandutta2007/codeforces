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
    if(n == 1){
        cout << "a" << endl;
        return 0;
    }
    for(int i = 0; i < n; ++i){
        if((i + 1) % 4 <= 1){
            cout << "a";
        }else{
            cout << "b";
        }
    }
    cout << endl;



}