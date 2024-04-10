#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,c=0;
    string s;
    cin >> n >> s;
    string res="";
    for (int i = 0; i < n; i+=2){
        if (s[i]!=s[i+1]){
            res += s[i];
            res += s[i+1];
        }else{
            res += "ab";
            c ++;
        }
    }
    cout << c << endl << res;
}