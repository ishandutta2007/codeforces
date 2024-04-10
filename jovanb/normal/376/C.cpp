#include <bits/stdc++.h>
using namespace std;

int del[]={1869, 6819, 1689, 6891, 1698, 1986, 1896, 1869};
int br[10];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0);
    cout.precision(10);
    cout<<fixed;

    int mod=0;
    string s;
    cin >> s;
    int n = s.size();
    for(int i=0; i<n; i++){
        br[s[i]-'0']++;
    }
    br[1]--;
    br[8]--;
    br[6]--;
    br[9]--;
    for(int i=1; i<=9; i++) while(br[i]--){cout << i; mod = (mod*10+i)%7;}
    mod = (mod*10000) % 7;
    cout << del[7-mod];
    while(br[0]--) cout << 0;
    return 0;
}