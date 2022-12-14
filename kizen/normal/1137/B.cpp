#include <bits/stdc++.h>

using namespace std;

const int NS = (int)5e5+4;
char s[NS], t[NS];
int fail[NS], N, M;
char ans[NS];
int cnt[3], tcnt[3], Tcnt[3];

int main(){
    scanf("%s %s", s, t); N = strlen(s), M = strlen(t);
    for(int i=1,j=0;i<M;++i){
        while(j>0&&t[i]!=t[j]) j = fail[j-1];
        if(t[i]==t[j]) fail[i] = ++j;
    }
    for(int i=0;i<N;++i) ++cnt[s[i]-'0'];
    for(int i=0;i<M;++i) ++Tcnt[t[i]-'0'];
    for(int i=fail[M-1];i<M;++i) ++tcnt[t[i]-'0'];
    int pos = 0, tpos=0;
    if(cnt[0]>=Tcnt[0]&&cnt[1]>=Tcnt[1]){
        while(cnt[0]>=tcnt[0]&&cnt[1]>=tcnt[1]){
            if(pos==0){
                cnt[0] -= Tcnt[0], cnt[1] -= Tcnt[1];
            }
            else cnt[0] -= tcnt[0], cnt[1] -= tcnt[1];
            while(tpos<M) ans[pos++] = t[tpos], ++tpos;
            tpos = fail[M-1];
        }
    }
    while(pos<N){
        if(cnt[0]) ans[pos++] = '0', --cnt[0];
        else ans[pos++] = '1', --cnt[1];
    }
    printf("%s\n", ans);
    return 0;
}