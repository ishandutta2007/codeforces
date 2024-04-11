#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef long long lint;

lint xs(lint x){
    if(x == 0) return 0;
    if(x%4 == 3) return 0;
    return xs(x-1) ^ x;
}

int main(){
    int n;
    scanf("%d",&n);
    lint ret = 0;
    while (n--) {
        lint s, e;
        scanf("%lld %lld",&s,&e);
        ret ^= (xs(s + e - 1) ^ xs(s-1));
    }
    puts(ret ? "tolik" : "bolik");
}