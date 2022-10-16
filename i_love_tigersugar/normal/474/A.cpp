#include<bits/stdc++.h>
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const string key[]={"qwertyuiop","asdfghjkl;","zxcvbnm,./"};
/*
qwertyuiop
asdfghjkl;
zxcvbnm,./
*/;
inline char ch(char c,int d) {
    REP(i,3) REP(j,key[i].size())
        if (key[i][j]==c) return (key[i][j+d]);
    assert(false);
}
int main(void) {
    char c;
    cin>>c;
    int d=(c=='L')?1:-1;
    string s;
    cin>>s;
    REP(i,s.size()) printf("%c",ch(s[i],d));
    return 0;
}