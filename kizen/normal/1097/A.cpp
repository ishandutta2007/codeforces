#include <bits/stdc++.h>

using namespace std;

int main(){
    char s[5], in[5];
    scanf("%s", s);
    for(int i=0;i<5;++i){
        scanf("%s", in);
        if(in[0]==s[0]||in[1]==s[1]){
            puts("YES");
            return 0;
        }
    }
    puts("NO");

    return 0;
}