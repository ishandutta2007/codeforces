#include <bits/stdc++.h>

using namespace std;

int N;
int cnt[14];

int main(){
    char c;
    scanf("%d", &N);
    while(N--){
        scanf(" %c", &c); ++cnt[c-'0'];
    }
    int ans = 0;
    while(1){
        if(!cnt[8]) break;
        --cnt[8];
        int T = 10;
        for(int i=0;i<8;++i) while(T&&cnt[i]) --cnt[i], --T;
        while(cnt[9]&&T) --cnt[9], --T;
        while(cnt[8]&&T) --cnt[8], --T;
        if(T) break;
        ++ans;
    }
    printf("%d", ans);
    return 0;
}