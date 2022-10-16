#include<bits/stdc++.h>
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int main(void) {
    string s;
    cin>>s;
    REP(i,s.size()) s[i]=min<int>(s[i],'9'-(s[i]-'0'));
    if (s[0]=='0') s[0]='9';
    cout<<s<<endl;
    return 0;
}