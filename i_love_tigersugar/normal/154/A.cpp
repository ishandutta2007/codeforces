#include<cstdio>
#include<cstring>
#include<vector>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int n,m;
char s[MAX];
bool fb[333][333];
void init(void) {
    scanf("%s",s+1);
    n=strlen(s+1);
    scanf("%d",&m);
    REP(zz,m) {
        char t[5];
        scanf("%s",t);
        fb[t[0]][t[1]]=fb[t[1]][t[0]]=true;
    }
}
int count(int l,int r) {
    int c[2];
    c[0]=c[1]=0;
    FOR(i,l,r) c[s[i]==s[l]]++;
    return (min(c[0],c[1]));
}
void process(void) {
    vector<int> v;
    v.push_back(1);
    FOR(i,1,n) if (i>1 && s[i]!=s[i-1] && !fb[s[i-1]][s[i]]) v.push_back(i);
    v.push_back(n+1);
    int res=0;
    REP(i,v.size()-1) res+=count(v[i],v[i+1]-1);
    printf("%d",res);
}
int main(void) {
    init();
    process();
    return 0;
}