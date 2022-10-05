#include<stdio.h>
#include<algorithm>
using namespace std;
int n,s,a,b,m=987654321;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        m=min(m,b);
        s+=a*m;
    }
    printf("%d",s);
}