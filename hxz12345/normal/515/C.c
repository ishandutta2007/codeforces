#include <stdio.h>
int n,i,x,f[20];
char s[20];
int main() {
    scanf("%d",&n);
    scanf("%s",s);
    for(i=0;i<n;i++) 
	    {
		x=s[i]-'0';
	    if (x==2) f[2]++;
	    if (x==3) f[3]++;
	    if (x==4) f[3]++,f[2]+=2;
	    if (x==5) f[5]++;
	    if (x==6) f[3]++,f[5]++;
	    if (x==7) f[7]++;
	    if (x==8) f[7]++,f[2]+=3;
	    if (x==9) f[7]++,f[3]+=2,f[2]++;
	    }
	for(i=1;i+8<f[7];i+=8)printf("77777777");
	while(i<=f[7])putchar('7'),i++;
	for(i=1;i+8<f[5];i+=8)printf("55555555");
	while(i<=f[5])putchar('5'),i++;
	for(i=1;i+8<f[3];i+=8)printf("33333333");
	while(i<=f[3])putchar('3'),i++;
	for(i=1;i+8<f[2];i+=8)printf("22222222");
	while(i<=f[2])putchar('2'),i++;
}