#include <cstdio>
#include <algorithm>
using namespace std;

int hi, ai, di;
int hj, aj, dj;
int able(int a, int d, int h){
    if(max(aj - di - d,0) == 0) return 1;
    if(max(ai - dj + a,0) == 0) return 0;
    if((hj - 1) / max(ai - dj + a,0) < (hi + h - 1) / max(aj - di - d,0)) return 1;
    return 0;
}

int main(){
    scanf("%d %d %d %d %d %d",&hi,&ai,&di,&hj,&aj,&dj);
    int hc, ac, dc;
long long ret = 1e18;
    scanf("%d %d %d",&hc,&ac,&dc);
    for (int a=0; a<=500; a++) {
        for (int d=0; d<=500; d++) {
            if(max(ai - dj + a,0) == 0){
                continue;
            }
            int hs = 0, he = 1e9;
            while (hs != he) {
                int hm = (hs + he) / 2;
                if(able(a,d,hm)) he = hm;
                else hs = hm+1;
            }
            ret = min(ret,1ll * hc * hs + ac * a + dc * d);
        }
    }
    printf("%I64d",ret);
}