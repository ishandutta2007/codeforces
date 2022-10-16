#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const char equ[]="Elephant";
const char diff[]="Bear";
const char none[]="Alien";
int len[6];
bool equFour(int x) {
    FOR(i,1,3) if (len[x+i]!=len[x]) return (false);
    return (true);
}
bool canEqu(void) {
    if (equFour(0) && len[4]==len[5]) return (true);
    if (equFour(1) && len[5]==len[0]) return (true);
    if (equFour(2) && len[0]==len[1]) return (true);
    return (false);
}
bool canDiff(void) {
    if (equFour(0) && len[4]!=len[5]) return (true);
    if (equFour(1) && len[5]!=len[0]) return (true);
    if (equFour(2) && len[0]!=len[1]) return (true);
    return (false);
}
int main(void) {
    REP(i,6) scanf("%d",&len[i]);
    sort(len,len+6);
    if (canEqu()) printf("%s",equ);
    else if (canDiff()) printf("%s",diff);
    else printf("%s",none);
    return 0;
}