#include <bits/stdc++.h>
using namespace std;

int res[1000005];
string s;

void print(int x){
    for(int i=0; i<x; i++) cout << s[i];
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    cin >> s;
    res[0] = 0;
    int l=0, n=s.size(), j=1;
    while(j < n){
        if(s[j] == s[l]) {res[j+1] = ++l; j++;}
        else if(l == 0){
            res[j+1] = 0;
            j++;
        }
        else l = res[l];
    }
    if(res[n] == 0){cout << "Just a legend"; return 0;}
    for(int i=1; i<n; i++){
        if(res[i] == res[n]){print(res[i]); return 0;}
    }
    int x=0;
    if(res[res[n]] != 0) x = max(x, res[res[n]]);
    if(x != 0) {print(x); return 0;}
    cout << "Just a legend";
    return 0;
}