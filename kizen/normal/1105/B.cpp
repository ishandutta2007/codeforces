#include <bits/stdc++.h>

using namespace std;

const int NS = (int)2e5+4;
int N, k;
char s[NS];
int sum[30];

int main(){
    scanf("%d %d %s", &N, &k, s);
    for(int i=0;i<N;++i){
        int j = i;
        while(s[j+1]==s[i]&&j-i+1<k) ++j;
        if(j-i+1==k) ++sum[s[i]-'a'];
        i = j;
    }
    int ans = 0;
    for(int i=0;i<26;++i) ans = max(ans, sum[i]);
    printf("%d", ans);
    return 0;
}