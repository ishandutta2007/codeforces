#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],y,s;
int main(){
    scanf("%d%d",&n,&m);
    while(n--){
        int a;
        scanf("%d",&a);
        a+=y;
        printf("%d ",a/m),y=a%m;
    }
    return 0;
}