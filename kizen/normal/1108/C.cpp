#include <bits/stdc++.h>

using namespace std;

const int NS = (int)2e5+4;
int N;
char s[NS];
int cnt[4];
char arr[7][4] = {"RGB", "RBG", "BRG", "BGR", "GRB", "GBR"};

int main(){
    scanf("%d", &N);
    scanf("%s", s);
    int ans = (int)1e9, num;
    for(int i=0;i<6;++i){
        int cnt = 0;
        for(int j=0;j<N;++j) if(s[j]!=arr[i][j%3]) ++cnt;
        if(cnt<ans){
            ans = cnt, num = i;
        }
    }
    printf("%d\n", ans);
    for(int j=0;j<N;++j) printf("%c", arr[num][j%3]);
    return 0;
}