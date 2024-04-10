#include <bits/stdc++.h>
using namespace std;
string s;
int c[200100],cc=1,res=1,N;
int main(){
    cin >> s;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'b') c[i] = 1;
        else c[i] = 0;
        c[i+s.size()] = c[i];}
    for (int i = 1; i < 2 * s.size(); i++){
        if (c[i] != c[i-1]) cc++;
        else cc = 1;
        res = max (res, cc);}
    cout << min (res, int(s.size()));}