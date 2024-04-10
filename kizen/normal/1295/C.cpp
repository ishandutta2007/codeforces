#include <bits/stdc++.h>

using namespace std;

const int NS = (int)1e5 + 4;
int T, SN, TN;
int last[27];
char s[NS], t[NS];
int nxt[NS][27];

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%s %s", s + 1, t + 1);
        SN = strlen(s + 1), TN = strlen(t + 1);
        memset(last, 0, sizeof(last));
        for(int i = SN; i >= 1; --i){
            last[s[i] - 'a'] = i;
        }
        for(int i = SN; i >= 0; --i){
            for(int j = 0; j < 27; ++j) nxt[i][j] = last[j];
            if(i) last[s[i] - 'a'] = i;
        }
        int pos = 0;
        int f = 0, ans = 1;
        for(int i = 1; i <= TN; ++i){
            if(!pos && i > 1){
                f = 1; break;
            }
            int np = nxt[pos][t[i] - 'a'];
            if(np <= pos) ++ans;
            pos = np;
        }
        if(!pos) f = 1;
        if(f) puts("-1");
        else printf("%d\n", ans);
    }
    return 0;
}