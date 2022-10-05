#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll ans;
char str[300010];

int main(){
    scanf("%s", str);
    for(int i = 0; str[i]; i++){
        if(str[i] == '0' || str[i] == '4' || str[i] == '8') ans++;
    }
    for(int i = 1; str[i]; i++){
        if(((str[i - 1] - '0') * 10 + (str[i] - 0)) % 4 == 0) ans += (ll)i;
    }
    printf("%I64d", ans);
}