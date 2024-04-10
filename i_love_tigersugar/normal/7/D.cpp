#include<bits/stdc++.h>
#define MAX   5000050
#define NMOD   1
typedef long long ll;
const ll base=97LL;
char s[MAX];
ll pw[MAX];
ll fhs[MAX];
ll bhs[MAX];
int lev[MAX];
int l;
int code(const char &c) {
    if ('A'<=c && c<='Z') return (c-'A');
    if ('a'<=c && c<='z') return (c-'a'+26);
    if ('0'<=c && c<='9') return (c-'0'+52);
    printf("%c",c);
    exit(1997);
}
void init(void) {
    scanf("%s",s);
    l=strlen(s);
    int i;
    pw[0]=1LL;
    for (i=1;i<=l;i=i+1) pw[i]=pw[i-1]*base;
    for (i=1;i<=l;i=i+1) fhs[i]=fhs[i-1]+pw[i-1]*code(s[i-1]);
    for (i=l;i>=1;i=i-1) bhs[i]=bhs[i+1]+pw[l-i]*code(s[i-1]);
}
bool palin(const int &a,const int &b) {
    ll x=fhs[b]-fhs[a-1];
    ll y=bhs[a]-bhs[b+1];
    if (a-1<l-b) x=x*pw[l-b-a+1];
    if (l-b<a-1) y=y*pw[a-1-l+b];
    return (x==y);
}
void process(void) {
    int i;
    lev[0]=0;
    ll res=0LL;
    for (i=1;i<=l;i=i+1) {
        if (palin(1,i)) lev[i]=lev[i/2]+1;
        else lev[i]=0;
        res=res+lev[i];
    }   
    printf("%I64d",res);
}
int main(void) {
    init();
    process();
    return 0;
}