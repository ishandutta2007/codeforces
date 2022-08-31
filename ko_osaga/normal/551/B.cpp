#include <cstdio>
#include <algorithm>
using namespace std;

char a[100005], b[100005], c[100005];

int c0[26], c1[26], c2[26];

int main(){
    scanf("%s %s %s",a,b,c);
    for (int i=0; a[i]; i++) {
        c0[a[i] - 'a']++;
    }
    for (int i=0; b[i]; i++) {
        c1[b[i] - 'a']++;
    }
    for (int i=0; c[i]; i++) {
        c2[c[i] - 'a']++;
    }
    int maxv = 0, maxp = -1;
    for (int i=0; i<=100000; i++) {
        int p = 1e9;
        for (int j=0; j<26; j++) {
            if(c0[j] - 1ll * c1[j] * i < 0){
                p = -1e9;
                break;
            }
            if(c2[j] == 0) continue;
            p = min(p,(c0[j] - c1[j] * i) / c2[j]);
        }
        if(maxv <= i + p) maxv = i + p, maxp = i;
    }
    int bcnt = maxp, ccnt = maxv - maxp;
    for (int i=0; i<bcnt; i++) {
        printf("%s",b);
    }
    for (int i=0; i<ccnt; i++) {
        printf("%s",c);
    }
    for (int j=0; j<26; j++) {
        c0[j] -= c1[j] * bcnt + c2[j] * ccnt;
        while (c0[j]--) {
            putchar(j + 'a');
        }
    }
}