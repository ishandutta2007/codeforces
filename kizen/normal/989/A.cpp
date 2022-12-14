#include <bits/stdc++.h>

using namespace std;

string s;

int main(){
    ios_base::sync_with_stdio(false);

    cin >> s;
    int f = 0;
    for(int i=0;i<(int)s.size()-2;i++){
        if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C') f = 1;
        if(s[i]=='A'&&s[i+1]=='C'&&s[i+2]=='B') f = 1;
        if(s[i]=='B'&&s[i+1]=='A'&&s[i+2]=='C') f = 1;
        if(s[i]=='B'&&s[i+1]=='C'&&s[i+2]=='A') f = 1;
        if(s[i]=='C'&&s[i+1]=='A'&&s[i+2]=='B') f = 1;
        if(s[i]=='C'&&s[i+1]=='B'&&s[i+2]=='A') f = 1;
    }
    if(f) puts("Yes");
    else puts("No");

    return 0;
}