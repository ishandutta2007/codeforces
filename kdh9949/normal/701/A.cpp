#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int a[101];
bool chk[101];
int s;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    for(int i = 1; i <= n; i++) s += a[i];
    s /= (n / 2);
    for(int i = 1; i <= n / 2; i++){
        int j = 1, k;
        while(chk[j]) j++;
        k = j + 1;
        while(1){
            if(!chk[k] && a[j] + a[k] == s) break;
            k++;
        }
        chk[j] = chk[k] = true;
        printf("%d %d\n", j, k);
    }
}