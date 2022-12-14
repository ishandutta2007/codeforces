#include <bits/stdc++.h>
using namespace std;

int N, M, Q;
const int LM = 1004;
char S[LM];
char T[LM];
int fail[LM];
int kmp[LM];

void makefail(){
    for(int i=1,j=0;i<M;i++){
        while(j>0&&T[i]!=T[j]) j = fail[j-1];
        if(T[i]==T[j]) fail[i] = ++j;
    }
}

int main(){
//    freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &N, &M, &Q);
    scanf("%s %s", S, T);

    makefail();

    while(Q--){
        int l, r;
        scanf("%d %d", &l, &r);
        for(int i=0;i<LM;++i) kmp[i] = 0;
        int ans = 0;
        for(int i=l-1,j=0;i<r;i++){
            while(j>0&&S[i]!=T[j]) j = fail[j-1];
            if(S[i]==T[j]){
                ++j;
                if(j==M){
                    ++ans;
                    j = fail[j-1];
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}