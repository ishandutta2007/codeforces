#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int a[200020], b[200020];
int ac, bc, acc, bcc;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", a + i);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", b + i);
    }
    for(ac = 0; a[ac] != 1; ac++);
    for(bc = 0; b[bc] != 1; bc++);
    for(int i = 0; i < n; i++){
        if(a[(i + ac + acc) % n] == 0) acc++;
        if(b[(i + bc + bcc) % n] == 0) bcc++;
        if(a[(i + ac + acc) % n] != b[(i + bc + bcc) % n]) {puts("NO"); return 0;}
    }
    puts("YES");
}