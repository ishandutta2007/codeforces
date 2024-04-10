#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
#define PI (3.14159265358979323)
using namespace std;

int N,i,j,k,l;
double x,y,A[100005],dm;

int main(){
    scanf("%d",&N);
    for (i=1; i<=N; i++){
        scanf("%lf%lf",&x,&y);
        A[i] = atan2(y,x);
    }
    sort(A+1,A+N+1);
    dm = 0;
    A[N+1] = A[1]+2*PI;
    for (i=1; i<=N; i++){
        if (A[i+1] - A[i] > dm) dm = A[i+1] - A[i];
    }
    printf("%.10lf\n",(180.0/PI)*(2*PI-dm));
    return 0;
}