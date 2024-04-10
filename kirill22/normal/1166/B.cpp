#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin >> n;
    int x = 1;
    for(int i = 5;i * i <= n;i++){
        if(n % i == 0){
            x = i;
            break;
        }
    }
    if(x == 1){
        cout << -1;
        return 0;
    }
    string s = "aeiou";
    if(n / x < 5){
        cout << -1;
        return 0;
    }
    string ans = "";
    int m = n / x;
    vector<vector<char>> g(m,vector<char> (x,'t'));
    vector<char> r;
    r.push_back('a');
    r.push_back('e');
    r.push_back('i');
    r.push_back('o');
    r.push_back('u');
    for(int i = 0;i < 5;i++){
            char c = r[i];
            int x1 = 0,y = i;
            while(x1 < m){
                g[x1][y] = c;
                if(y == x - 1){
                    y = 0;
                }
                else{
                    y++;
                }
                x1++;
            }
    }
    for(int i =0;i<m;i++){
        for(int u=0;u<x;u++){
            cout << g[i][u];
        }
    }


}