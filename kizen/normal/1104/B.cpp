#include <bits/stdc++.h>

using namespace std;

char s[100004];
int stk[100004], top;

int main(){
    scanf("%s", s);
    int len = strlen(s);
    int ans = 0;
    for(int i=0;i<len;++i){
        if(!top||stk[top-1]!=s[i]) stk[top++] = s[i];
        else --top, ++ans;
    }
    printf("%s", ans%2? "Yes":"No");
    return 0;
}