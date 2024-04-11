#include <cstdio>
#include <algorithm>
using namespace std;

int arr[100005], n, k;

int main(){
    scanf("%d %d",&n,&k);
    int s = 1, e = n;
    for(int i=1; i<=n && i<=k; i++){
        if(i%2) printf("%d ", s++);
        else printf("%d ", e--);
    }
    if(k%2)for(int i=s; i<=e; i++){
        printf("%d ",i);
    }
    else{
        for(int i=e; i>=s; i--){
        printf("%d ",i);
    }
    }
}