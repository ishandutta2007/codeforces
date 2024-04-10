#include "bits/stdc++.h"
using namespace std;

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    map<char, int> cow;

    int num = 0;
    for(char c : s){
        if(cow.find(c) == cow.end()){
            cow[c] = 1;
            ++num;
        }
        ++num;
    }

    cout << num << '\n';
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}