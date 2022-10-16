#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define MASK(i) (1<<(i))
#define BIT(x,i) (((x)>>(i))&1)
using namespace std;
char s[MAX],t[MAX];
int a[MAX],b[MAX];
int next[MAX],ls,lt;
int appMask[MAX],tMask;
int matchS[MAX];
void init(void) {
    scanf("%d%d",&ls,&lt);
    scanf("%s",s+1);
    scanf("%s",t+1);
}
void checkMatch(char x,char y) {
    //printf("For %c and %c\n",x,y);
    FOR(i,1,ls) {
        if (s[i]==x) a[i]=1;
        else if (s[i]==y) a[i]=2;
        else a[i]=0;
    }
    FOR(i,1,lt) {
        if (t[i]==y) b[i]=1;
        else if (t[i]==x) b[i]=2;
        else b[i]=0;
    }
    //FOR(i,1,ls) printf("%d ",a[i]); printf("\n");
    //FOR(i,1,lt) printf("%d ",b[i]); printf("\n");
    int j=next[1]=0;
    FOR(i,2,lt) {
        while (j>0 && b[i]!=b[j+1]) j=next[j];
        if (b[i]==b[j+1]) j++;
        next[i]=j;
    }
    j=0;
    FOR(i,1,ls) {
        while (j>0 && a[i]!=b[j+1]) j=next[j];
        if (a[i]==b[j+1]) j++;
        if (j==lt) {
            //printf("Match %d %c %c\n",i-lt+1,x,y);
            matchS[i-lt+1]|=MASK(x-'a')|MASK(y-'a');
            j=next[j];
        }
    }
}
bool okPos(int i) {
    if (__builtin_popcount(appMask[i])!=__builtin_popcount(tMask)) return (false);
    return ((matchS[i]&appMask[i])==appMask[i]);
}
void process(void) {
    int haveMask=0;
    int cnt[26];
    memset(cnt,0,sizeof cnt);
    FOR(i,1,ls) {
        if (cnt[s[i]-'a']++==0) haveMask|=MASK(s[i]-'a');
        if (i>lt) {
            if (--cnt[s[i-lt]-'a']==0) haveMask&=~MASK(s[i-lt]-'a');
        }
        if (i>=lt) appMask[i-lt+1]=haveMask;
    }
    FOR(i,1,lt) tMask|=MASK(t[i]-'a');
    FOR(x,'a','z') FOR(y,x,'z') if (BIT(tMask,x-'a') || BIT(tMask,y-'a')) checkMatch(x,y);
    vector<int> pos;
    FOR(i,1,ls-lt+1) if (okPos(i)) pos.push_back(i);
    printf("%d\n",(int)pos.size());
    if (!pos.empty()) {
        REP(i,pos.size()) printf("%d ",pos[i]); printf("\n");
    }
}
int main(void) {
    init();
    process();
    return 0;
}