#include<bits/stdc++.h>
using namespace std;
const string noAnswer="No such string";
int main(void) {
    ios::sync_with_stdio(true);
    string s,t;
    cin>>s>>t;
    int id=s.size()-1;
    while (id>=0 && s[id]=='z') {
        s[id]='a';
        id--;
    }
    s[id]++;
    if (s<t) cout<<s<<endl; else cout<<noAnswer<<endl;
    return 0;
}