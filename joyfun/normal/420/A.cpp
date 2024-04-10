#include <cstdio>
#include <cstring>
using namespace std;

char s[100005];

int main(){
    int n=strlen(gets(s));
    for(int i=0;i<n;i++)
        if("A......HI...M.O....TUVWXY."[s[n-i-1]-'A']!=s[i])
            return puts("NO"),0;
    puts("YES");
}