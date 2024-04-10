#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long suma;
int N,K,l,r;

int main(){
    scanf("%d%d",&N,&K);
    while (N--){
        scanf("%d%d",&l,&r);
        suma += r-l+1;
    }
    l = (K-(suma % K))%K;
    printf("%d\n",l);
    return 0;
}