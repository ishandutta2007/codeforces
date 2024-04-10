#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

double n,m,sol;

int main(){
    scanf("%lf%lf",&n,&m);
    if (n==1 && m==1) sol = 1; else sol = (m+n - 2*m*n)/(n-m*n*n);
    printf("%.18lf\n",sol);
    return 0;
}