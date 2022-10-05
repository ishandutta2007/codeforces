#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
ll a[30], last, ans;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%I64d", a + i);
    sort(a, a + n);
    last = ans = a[n - 1];
    for(int i = n - 2; i >= 0; i--){
        if(last == 0 || a[i] == 0) break;
        if(a[i] >= last) ans += --last;
        else ans += a[i], last = a[i];
    }
    printf("%I64d", ans);
}