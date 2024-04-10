#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;

int A,B,C,a,b,c;

int kor(int x){
    int r = (int)sqrt(x);
    if (r*r == x) return r;
    if (r*r+2*r+1 == x) return r+1;
}

int main(){
    scanf("%d%d%d",&A,&B,&C);
    b = kor(A*B/C);
    a = A/b;
    c = C/a;
    printf("%d\n",4*(a+b+c));
    return 0;
}