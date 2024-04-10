#include<bits/stdc++.h>
#define MAX   55
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const string goal="acef";
char a[MAX][MAX];
int m,n;
bool ok(int x,int y) {
    string s;
    REP(i,2) REP(j,2) s.push_back(a[x+i][y+j]);
    sort(s.begin(),s.end());
    return (s==goal);
}
void process(void) {
    scanf("%d%d",&m,&n);
    FOR(i,1,m) scanf("%s",a[i]+1);
    int res=0;
    FOR(i,1,m-1) FOR(j,1,n-1) if (ok(i,j)) res++;
    printf("%d\n",res);
}
int main(void) {
    process();
    return 0;
}