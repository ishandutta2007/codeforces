#include <cstdio>

int main(){
int a,b,c;
scanf("%d%d%d",&a,&b,&c);
b--;
b += c + 1000*a;
b%=a;
b++;
printf("%d",b);
}