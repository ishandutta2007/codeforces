#include <stdio.h>

const char name[5][10]={"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

int main(void)
{
	int n,m,i;
	while(scanf("%d",&n)==1) {
		m=1;
		i=0;
		while(1) {
			n-=m;
			if(n<=0) break;
			i++;
			if(i==5) {
				i=0;
				m*=2;
			}
		}
		puts(name[i]);
	}
}