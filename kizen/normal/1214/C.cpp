#include <bits/stdc++.h>

using namespace std;

const int NS = (int)2e5 + 4;
int N;
char s[NS];

int main(){
    scanf("%d", &N);
    scanf("%s", s + 1);
    int cnt = 0, f = 0;
    for(int i = 1; i <= N; ++i){
        if(s[i] == '(') ++cnt;
        else{
            if(!cnt){
                if(!f){
                    f = 1;
                }
                else{
                    puts("No"); return 0;
                }
            }
            else{
                --cnt;
            }
        }
    }
    if(cnt - f == 0){
        puts("Yes");
    }
    else puts("No");
    return 0;
}