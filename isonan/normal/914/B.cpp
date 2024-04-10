#include <cstdio>

int n,a[100001],count[100001],nowans,f[100001];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        count[a[i]]++;
        if(nowans<a[i])nowans=a[i];
    }
    for(int i=1;i<=n;i++){
        if(count[a[i]]%2){
            puts("Conan");
            return 0;
        }
    }
    puts("Agasa");
}