//Problem A
#include<bits/stdc++.h>
using namespace std;
int a[3];
int main(){
    scanf("%d%d%d",&a[0],&a[1],&a[2]);
    sort(a,a+3);
    printf("%d",max(0,a[2]-a[1]-a[0]+1));
    return 0;
}