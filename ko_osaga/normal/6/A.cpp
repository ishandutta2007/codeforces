#include <cstdio>
#include <algorithm>
using namespace std;

int solve(int a, int b, int c){
    if(a + b == c) return 0;
    if(a + b > c) return 1;
    return -1;
}

int main(){
    int a[4];
    scanf("%d %d %d %d",&a[0],&a[1],&a[2],&a[3]);
    sort(a,a+4);
    int ret = -1;
    ret = max(ret,solve(a[0],a[1],a[2]));
    ret = max(ret,solve(a[0],a[1],a[3]));
    ret = max(ret,solve(a[0],a[2],a[3]));
    ret = max(ret,solve(a[1],a[2],a[3]));
    if(ret > 0) puts("TRIANGLE");
    else if(ret == 0) puts("SEGMENT");
    else puts("IMPOSSIBLE");
}