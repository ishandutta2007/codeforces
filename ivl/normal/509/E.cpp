#include <cstdio>

using namespace std;

char s[500005];
int l;

long double pr[500005];
bool good[256];

int main(){
    good['A'] = good['E'] = good['I'] = good['O'] = good['U'] = good['Y'] = true;
    
    scanf("%s", s);
    while (s[l] != '\0') ++l;
    
    pr[0] = 0;
    for (int i = 1; i <= 500000; ++i) pr[i] = pr[i - 1] + 1.0 / (long double)i;
    
    long double R = 0;
    long double CR = 0;
    
    for (int i = 0; i < l; ++i){
        CR -= pr[i];
        CR += pr[l - i];
        if (!good[s[i]]) continue;
        R += CR;
    }
    printf("%.9lf\n", (double)R);
    return 0;
}