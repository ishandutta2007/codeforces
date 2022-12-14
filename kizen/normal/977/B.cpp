#include <bits/stdc++.h>
using namespace std;

const int AS = 30;
int cnt[AS][AS];
int N;
char s[104];

int main(){
    scanf("%d", &N);
    scanf("%s", s);
    for(int i=0;i<N-1;i++) cnt[s[i]-'A'][s[i+1]-'A']++;
    int ans = 0;
    for(int i=0;i<AS;i++) for(int j=0;j<AS;j++) ans = max(ans, cnt[i][j]);
    for(int i=0;i<AS;i++) for(int j=0;j<AS;j++) if(ans==cnt[i][j]){
        printf("%c%c", i+'A', j+'A');
        return 0;
    }

    return 0;
}