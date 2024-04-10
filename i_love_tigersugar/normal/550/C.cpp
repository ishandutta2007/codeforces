#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
string s;
int n;
int main(void) {
    cin>>s;
    n=s.size();
    REP(i,n) s[i]-='0';
    REP(i,n) if (s[i]%8==0) {
        printf("YES\n%d\n",s[i]);
        return 0;
    }
    REP(i,n) FOR(j,i+1,n-1) if ((s[i]*10+s[j])%8==0) {
        printf("YES\n%d%d\n",s[i],s[j]);
        return 0;
    }
    REP(i,n) FOR(j,i+1,n-1) FOR(k,j+1,n-1) if ((s[i]*100+s[j]*10+s[k])%8==0) {
        printf("YES\n%d%d%d\n",s[i],s[j],s[k]);
        return 0;
    }
    printf("NO\n");
    return 0;
}