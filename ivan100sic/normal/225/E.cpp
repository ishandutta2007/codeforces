#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 1000000007ll
using namespace std;

long long x,y,N,Mp[40] = {1,2,4,6,12,16,18,30,60,88,106,126,520,606,1278,2202,2280,3216,4252,4422,9688,
9940,11212,19936,21700,23208,44496,86242,110502,132048,216090,756838,859432,1257786,1398268,2976220,3021376,6972592,13466916,20996010};
bool moze;

long long stepen(long long x,long long p){
    if (p==0) return 1;
    if (p==1) return x;
    long long r;
    r = stepen(x,p/2);
    r = (r*r)%MOD;
    if (p%2){
        r*=x;
        r%=MOD;
    }
    return r;
}

int main(){
    scanf("%d",&N);
    printf("%d\n",stepen(2,Mp[N-1])-1);
    return 0;
}