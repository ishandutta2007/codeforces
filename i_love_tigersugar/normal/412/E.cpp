#include<bits/stdc++.h>
#define MAX   1000100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
typedef long long ll;
char s[MAX];
int l[MAX],r[MAX],c[MAX],next[MAX];
int n;
inline bool ischar(char c) {
    return ('a'<=c && c<='z');
}
inline bool isdigit(char c) {
    return ('0'<=c && c<='9');
}
void process(void) {
    scanf("%s",s+1);
    n=strlen(s+1);
    FOR(i,1,n) c[i]=c[i-1]+ischar(s[i]);
    FOR(i,1,n) {
        if (s[i]=='@') {
            l[i]=i-1;
            while (l[i]>0 && (ischar(s[l[i]]) || isdigit(s[l[i]]) || s[l[i]]=='_')) l[i]--;
            next[i]=i+1;
            while (next[i]<=n && s[next[i]]!='.') {
                if (!ischar(s[next[i]]) && !isdigit(s[next[i]])) {
                    next[i]=n+1;
                    break;
                }
                next[i]++;
            }
            //printf("Left %d = %d\n",i,l[i]);
            //printf("Next %d = %d\n",i,next[i]);
        }
        if (s[i]=='.') {
            r[i]=i+1;
            while (r[i]<=n && ischar(s[r[i]])) r[i]++;
            //printf("Right %d = %d\n",i,r[i]);
        }
    }
    ll res=0;
    FOR(i,1,n) if (s[i]=='@' && next[i]>i+1 && next[i]<=n) res+=1LL*(c[i]-c[l[i]])*(r[next[i]]-next[i]-1);
    cout<<res;
}
int main(void) {
#ifndef ONLINE_JUDGE
    //freopen("tmp.txt","r",stdin);
#endif
    process();
    return 0;
}