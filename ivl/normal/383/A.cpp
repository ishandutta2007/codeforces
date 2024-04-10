#include <cstdio>

using namespace std;

int n;
int in[200005];

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", in + i);
    long long cnt = 0, rez = 0;
    for (int i = 0; i < n; ++i){
        if (in[i] == 0) rez += cnt;
        else ++cnt;
    }
    printf("%I64d\n", rez);
    return 0;
}