#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int tt;
    int a,b;
    scanf("%d",&tt);
    while (tt--){
        scanf("%d%d",&a,&b);
        if (a>b) swap(a,b);
        if (b>2*a){
            puts("NO"); continue;
        }
        a-=(b-a);
        puts(a%3?"NO":"YES");
    }
    return 0;
}