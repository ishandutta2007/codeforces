#include <cstdio>
#include <algorithm>
using namespace std;

int a[5];
int ans = 1e9;
int sum;

int main(){
    scanf("%d%d%d%d%d", a, a + 1, a + 2, a + 3, a + 4);
    sum = a[0] + a[1] + a[2] + a[3] + a[4];
    ans = sum;
    sort(a, a + 5);
    for(int i = 4; i >= 2; i--){
        if(a[i] == a[i - 1] && a[i - 1] == a[i - 2]){
            ans = min(ans, sum - a[i] - a[i - 1] - a[i - 2]);
            break;
        }
    }
    for(int i = 4; i >= 1; i--){
        if(a[i] == a[i - 1]){
            ans = min(ans, sum - a[i] - a[i - 1]);
            break;
        }
    }
    printf("%d", ans);
}