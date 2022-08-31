#include <cstdio>
#include <algorithm>
using namespace std;

int a[100005];
int main(){
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    printf("%d",*max_element(a,a+n));
}