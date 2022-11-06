//Problem C
#include<bits/stdc++.h>
using namespace std;

int n,m,x=1;
void op(int v){if(9<v)op(v/10);putchar(v%10+48);}
int main(){
    scanf("%d",&n);m=n;
    while(m!=1){
        int cur=2;
        for(int i=2;i<=m;i++)if(m/i>=m/cur)cur=i;//printf("cur=%d ",cur);
        for(int i=1;i<=m-m/cur;i++)op(x),putchar(' ');
        x*=cur;m/=cur;
    }
    op(x);
    return 0;
}