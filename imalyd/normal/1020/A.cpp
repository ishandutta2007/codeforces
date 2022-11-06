//Problem A
#include<bits/stdc++.h>
using namespace std;

int n,h,l,r,k;

int main(){
    scanf("%d%d%d%d%d",&n,&h,&l,&r,&k);
    while(k--){
        int a,b,c,d,e;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(a==c)e=abs(b-d);
        else if(r<b&&r<d)e=b-r+d-r;
        else if(b<l&&d<l)e=l-b+l-d;
        else e=abs(b-d);
        printf("%d\n",e+abs(a-c));
    }
    return 0;
}