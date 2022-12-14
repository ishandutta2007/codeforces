#include <bits/stdc++.h>

using namespace std;

int T;
int N;
char s[104];

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %s", &N, s);
        int cnt1 = 0, cnt2 = 0;
        for(int i=0;s[i]!='>'&&i<N;++i) ++cnt1;
        for(int i=N-1;s[i]!='<'&&i>=0;--i) ++cnt2;
        if(cnt1==N) cnt1 = 0;
        if(cnt2==N) cnt2 = 0;
        printf("%d\n", min(cnt1, cnt2));
    }
    return 0;
}