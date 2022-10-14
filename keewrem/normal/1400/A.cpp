#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

ll N,T;


int main(){
    cin >> T;
    string s;
    while(T--){
        cin >> N;
        cin >> s;
        for(int i = 0; i < 2*N; i+=2)cout << s[i];
        cout << "\n";
    }
    return 0;
}