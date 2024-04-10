#include<bits/stdc++.h>
#define MAX   300300
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int cnt,n,q;
char s[MAX];
void process(void) {
    scanf("%d%d",&n,&q);
    scanf("%s",s+1);
    FOR(i,1,n-1) if (s[i]=='.' && s[i+1]=='.') cnt++;
    REP(love,q) {
        int bef=0;
        int aft=0;
        int pos;
        char c[3];
        scanf("%d%s",&pos,c);
        FOR(i,pos-1,pos) if (s[i]=='.' && s[i+1]=='.') bef++;
        s[pos]=c[0];
        FOR(i,pos-1,pos) if (s[i]=='.' && s[i+1]=='.') aft++;
        cnt+=aft-bef;
        printf("%d\n",cnt);
    }
}
int main(void) {
    process();
    return 0;
}