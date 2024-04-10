#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
double broj,x,suma,best;

int main(){
    scanf("%d",&N);
    while (N--){
        scanf("%lf",&x);
        suma += x;
        broj += 1;
        if (suma/broj > best) best = suma/broj;
    }
    printf("%.6lf\n",best);
    return 0;
}