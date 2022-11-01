#include <cstdio>

using namespace std;

char L(char c){if (c >= 'A' && c <= 'Z') return c - 'A' + 'a'; return c;}

char in[8];
int val[256];

int main(){
    val['q'] = 9;
    val['r'] = 5;
    val['b'] = val['n'] = 3;
    val['p'] = 1;
    int R = 0;
    for (int i = 0; i < 8; ++i){
        scanf("%s", in);
        for (int j = 0; j < 8; ++j){
            char c = in[j];
            char cc = L(c);
            if (c != cc) R += val[cc]; else R -= val[cc];
        }
    }
    if (R > 0) printf("White\n");
    if (R < 0) printf("Black\n");
    if (R == 0) printf("Draw\n");
    return 0;
}