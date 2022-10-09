#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

double A[100005],sol;
int N,i,j,k;

void resi(int l,int r){
    if (l>r) return;
    if (l==r){
        sol += A[l];
        return;
    }
    int m = (l+r)/2;
    double sl,sr,xt;
    sl=0.0;
    sr=1.0;
    int i,j,k;
    xt=1;
    for (i=m; i>=l; i--){
        xt*=A[i];
        sl+=xt;
    }
    xt=1;
    for (i=m+1; i<=r; i++){
        xt*=A[i];
        sr+=xt;
    }
    //printf("%d %d %.4lf %.4lf\n",l,r,sl,sr);
    sol += 2*sl*sr;
    resi(l,m-1);
    sol -= A[m];
    resi(m+1,r);
}

int main(){
    scanf("%d",&N);
    for (i=1; i<=N; i++) scanf("%lf",A+i);
    resi(1,N);
    printf("%.14lf\n",sol);
    return 0;
}