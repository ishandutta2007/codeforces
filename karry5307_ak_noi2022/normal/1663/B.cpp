#include<cstdio>
using namespace std;
int main()
{
    int n=0;scanf("%d",&n);
    if(n<1200)printf("1200\n"); 
    if(n>=1200&&n<1400)printf("1400\n"); 
    if(n>=1400&&n<1600)printf("1600\n"); 
    if(n>=1600&&n<1900)printf("1900\n"); 
    if(n>=1900&&n<2100)printf("2100\n"); 
    if(n>=2100&&n<2300)printf("2300\n"); 
    if(n>=2300&&n<2400)printf("2400\n"); 
    if(n>=2400&&n<2600)printf("2600\n"); 
    if(n>=2600&&n<3000)printf("3000\n"); 
}