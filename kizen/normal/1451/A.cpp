#include <bits/stdc++.h>

using namespace std;

using LL = long long;
const int MOD = (int)1e9 + 7;
const int NS = (int)1004;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, N;
    cin >> T;
    while(T--){
        cin >> N;
        if(N == 1){
            cout << "0\n";
        }
        else if(N == 2){
            cout << "1\n";
        }
        else if(N == 3){
            cout << "2\n";
        }
        else if(N % 2){
            cout << "3\n";
        }
        else{
            cout << "2\n";
        }
    }
    return 0;
}