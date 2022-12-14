#include <bits/stdc++.h>

using namespace std;

const int NS = (int)1e5+4;
int N;
char s[NS];
map < char, int > mp;

int main(){
    scanf("%d", &N);
    scanf("%s", s+1);
    int f = 1;
    for(int i=1;i<=N;++i){
        if(s[i]!=s[1]){
            f = 0; break;
        }
    }
    if(f){
        puts("Yes"); return 0;
    }
    for(int i=1;i<=N;++i){
        if(mp[s[i]]){
            puts("Yes"); return 0;
        }
        mp[s[i]] = 1;
    }
    puts("No");

    return 0;
}