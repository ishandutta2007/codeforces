#include <cstdio>
#include <algorithm>
using namespace std;

int n,a[200005];
int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int min = a[0];
    int max = a[n-1];
    long long minn = 0, maxn = 0;
    for (int i=0; i<n; i++) {
        if(a[i] == min) minn++;
        if(a[i] == max) maxn++;
    }
    if(min != max){
        printf("%d %I64d",max-min,minn*maxn);
    }
    else{
        printf("0 %I64d",minn*(minn-1)/2);
    }
    // if both are same
}