#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const char yes[]="yes";
const char no[]="no";
char a[1111];
int n;
int main(void) {
    scanf("%d",&n);
    scanf("%s",a+1);
    FOR(i,1,n) FOR(d,1,n) {
        bool ok=true;
        REP(j,5) if (i+j*d>n || a[i+j*d]=='.') ok=false;
        if (ok) {
            printf("%s\n",yes);
            return 0;
        }
    }
    printf("%s\n",no);
    return 0;
}