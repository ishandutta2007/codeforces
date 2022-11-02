#include <stdio.h>

int main(void)
{
	int x,y,s,q;
	bool f=0;
	while(scanf("%d %d",&x,&y)==2) {
		while(1) {
			s=220;
			if(!f) {
				while(x&&s>=100) {
					x--;
					s-=100;
				}
				while(y&&s) {
					y--;
					s-=10;
				}
				if(s) {
					puts("Hanako");
					break;
				}
			} else {
				if(y*10>=s%100) {
					y-=s%100/10;
					s-=s%100;
				}
				while(y>=10&&s>=100) {
					y-=10;
					s-=100;
				}
				while(x&&s>=100) {
					x--;
					s-=100;
				}
				if(s) {
					puts("Ciel");
					break;
				}
			}
			f=!f;
		}
	}
	return 0;
}