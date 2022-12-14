#include <bits/stdc++.h>

using namespace std;

const int NS = (int)1e5 + 4;
int T;
int N, x;
char arr[NS];

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &x);
        scanf("%s", arr + 1);
        int cnt = 0;
        for(int i = 1; i <= N; ++i){
            if(arr[i] == '0') ++cnt;
            else --cnt;
        }
        int gap = 0, ans = 0, f = 0;
        for(int i = 1; i <= N; ++i){
            if(arr[i] == '0') ++gap;
            else --gap;
            if(cnt && gap == x) ++ans;
            if(cnt > 0 && gap < x && (x - gap) % cnt == 0) ++ans;
            else if(cnt < 0 && gap > x && (gap - x) % cnt == 0) ++ans;
            if(!cnt && gap == x) f = 1;
        }
        if(!x) ++ans;
        if(f) puts("-1");
        else printf("%d\n", ans);
    }
    return 0;
}