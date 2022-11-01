#include <cstdio>
#include <algorithm>

using namespace std;

char in[1005];
int l;

int main(){
    scanf("%s", in);
    while (in[l] != '\0') in[l++] -= '0';
    //bool back = true;
    for (int i = 0; i < l; ++i){
        if (in[i] != 9 || i != 0) in[i] = min((int)in[i], 9 - in[i]) + '0'; else in[i] = '9';
    //    back &= (in[i] == '0');
    }
    //if (back) in[l - 1] = '9';
    //char *p = in; while (*p == '0') ++p;
    printf("%s\n", in);
    return 0;
}