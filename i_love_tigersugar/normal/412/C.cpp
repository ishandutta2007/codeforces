#include<bits/stdc++.h>
#define MAX   100100
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
inline char fit(int x) {
    char ret=0;
    REP(i,26) if (x&(1<<i)) {
        if (ret>0) return ('?');
        ret=i+'a';
    }
    return (ret>0?ret:'z');
}
int used[MAX];
int main(void) {
    ios::sync_with_stdio(false);
    int n,len;
    cin>>n;
    REP(zz,n) {
        string s;
        cin>>s;
        len=s.size();
        REP(i,len) if (s[i]!='?') used[i]|=1<<(s[i]-'a');
    }
    REP(i,len) printf("%c",fit(used[i]));
    return 0;
}