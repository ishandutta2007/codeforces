#include <bits/stdc++.h>

using namespace std;

const int NS = (int)3e5+4;
int N;
char s[NS];

int main(){
    scanf("%d", &N);
    scanf("%s", s+1);
    int cnt = 0;
    for(int i=1;i<=N;++i) if(s[i]=='(') ++cnt;
    if(N%2||cnt>N/2){
        puts(":("); return 0;
    }
    cnt = N/2-cnt;
    int val = 0;
    for(int i=1;i<=N;++i){
        if(s[i]=='(') ++val;
        else if(s[i]==')') --val;
        else{
            if(cnt) ++val, --cnt, s[i] = '(';
            else --val, s[i] = ')';
        }
        if(val<=0&&i<N){
            puts(":("); return 0;
        }
        if(i==N&&val!=0){
            puts(":("); return 0;
        }
    }
    printf("%s\n", s+1);
    return 0;
}