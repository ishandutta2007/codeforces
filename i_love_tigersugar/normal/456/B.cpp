#include<bits/stdc++.h>
using namespace std;
int main(void) {
    string s;
    cin>>s;
    s="00"+s;
    int m=(s[s.size()-2]*10+s[s.size()-1])%4;
    if (m) cout<<0; else cout<<4;
    return 0;
}