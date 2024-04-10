#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[1000001];
unsigned z[1000000];

inline unsigned strcmpn(unsigned i, unsigned j) {
    unsigned n = 0;
    while(s[i] && s[i++] == s[j++])
        n++;
    return n;
}

int main(){
    scanf("%s", s);
    unsigned len = strlen(s), l = 0, r = 0;
    for(unsigned i = 1; i < len; i++) {
        if(i >= r) {
            unsigned x = strcmpn(0, i);
            l = i;
            r = i + x;
            z[i] = x;
        } else {
            if(i + z[i - l] < r) {
                z[i] = z[i - l];
            } else {
                unsigned x = strcmpn(r - i, r);
                l = i;
                r = r + x;
                z[i] = r - i;
            }
        }
    }
    // solve problem
    unsigned maxi = 0;
    for(unsigned i = 1; i < len; i++) {
        if(z[i] == len - i && maxi >= z[i]) {
            puts(s + i);
            goto end_case;
        }
        maxi = max(maxi, z[i]);
    }
    puts("Just a legend");
    end_case:;
}