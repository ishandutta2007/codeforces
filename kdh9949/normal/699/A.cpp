#include <cstdio>
#include <algorithm>
using namespace std;

int n;
char input[200010];
int a[200010];
int ans = 2141231231;

int main(){
    scanf("%d%s", &n, input);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    for(int i = 1; i < n; i++){
        if(input[i - 1] == 'R' && input[i] == 'L'){
            ans = min(ans, a[i] - a[i - 1]);
        }
    }
    if(ans == 2141231231) puts("-1");
    else printf("%d", ans / 2);
}