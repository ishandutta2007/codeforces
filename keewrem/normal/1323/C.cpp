#include <bits/stdc++.h>
using namespace std;
int n,t;
string s;
int main(){
    cin >> n;
    cin >> s;
    int bal = 0,res = 0;
    int first = 0;
    for(int i = 0; i < n; i++){
        if(bal == -1 && s[i]=='(')res+=i-first+1;
        if(s[i]=='(')bal++;
        if(bal == 0 && s[i]==')')first = i;
        if(s[i]==')') bal --;

    }
    if(bal  != 0)cout << "-1\n";
    else cout << res << "\n";
    return 0;
}