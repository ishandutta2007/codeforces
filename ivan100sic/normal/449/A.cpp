#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long x,y,k,xsize,a,ysize,b,opt;

int main(){
    scanf("%lld%lld%lld",&x,&y,&k);
    k += 2;
    if (k > x+y){
        printf("-1\n");
        return 0;
    }
    //iteriramo po xsize
    for (xsize=1; xsize*xsize<=2*x; xsize++){
        a = x / xsize;
        //printf("%lld %lld\n",a,xsize);
        if (a > k-1) a = k-1;
        b = k - a;
        if (b<1 || a<1) continue;
        ysize = y / b;
        opt = max(opt , (x/a) * ysize);
    }
    //iteriramo po a
    for (a=1; a*a<=2*x; a++){
        xsize = x / a;
        b = k - a;
        if (b<1 || a<1) continue;
        ysize = y / b;
        opt = max(opt , xsize * ysize);
    }
    printf("%lld\n",opt);
    return 0;
}