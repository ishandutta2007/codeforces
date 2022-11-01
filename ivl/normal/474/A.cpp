#include <cstdio>

using namespace std;

/*
qwertyuiop
asdfghjkl;
zxcvbnm,./
*/

// 10

char pt[] = {"qwertyuiopasdfghjkl;zxcvbnm,./"};

int pp[300];

char c;
char r[1005];

int main(){
    for (int i = 0; i < 30; ++i)
    pp[pt[i]] = i;
    
    scanf("%c%s", &c, r);
    int ch = 1;
    if (c == 'L') ch = -1;
    for (int i = 0; r[i] != '\0'; ++i){
        r[i] = pt[pp[r[i]] - ch];
    }
    printf("%s\n", r);
    return 0;
}