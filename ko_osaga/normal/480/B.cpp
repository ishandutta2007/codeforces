#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int a[100005],n,l,x,y;
int fa, fb;

int search_dist(int x){
    if(x == l) return 1;
    for (int i=0; a[i] <= l-x && i<n; i++) {
        if(binary_search(a,a+n,a[i]+x)) return 1;
    }
    return 0;
}

void calc(){
    for (int i=0; i<n && a[i] + y - x <= l; i++) {
        if(binary_search(a,a+n,a[i]+y-x)){
            if(a[i]>=x){
                printf("1\n%d",a[i]-x);
                exit(0);
            }
            else if(a[i]<=l-y){
                printf("1\n%d",a[i]+y);
                exit(0);
            }
        }
    }
    for (int i=0; i<n && a[i] + x + y <= l; i++) {
        if(binary_search(a,a+n,a[i]+x+y)){
            printf("1\n%d",a[i]+x);
            exit(0);
        }
    }
}
int main(){
    scanf("%d %d %d %d",&n,&l,&x,&y);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    fa = search_dist(x);
    fb = search_dist(y);
    if(fa && fb){
        puts("0");
    }
    else if(fa == 1 && fb == 0){
        printf("1\n%d",y);
    }
    else if(fa == 0 && fb == 1){
        printf("1\n%d",x);
    }
    else{
        calc();
        printf("2\n%d %d",x,y);
    }
}