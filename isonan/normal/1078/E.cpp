#include <cstdio>

void rep(const char *s,int x){
	for(int i=1;i<=x;i++)printf("%s",s);
}
void leading0(){
	putchar('1');
	putchar('r');
	rep("0srt",30);
	rep("lst",30);
	putchar('l');
	putchar('e');
}
int main(){
	printf("r0l");
	rep("l",31);
	leading0();
	putchar('u');
	leading0();
	putchar('u');
	putchar('u');
	putchar('u');
	rep("r1",31);
	putchar('d');
	putchar('d');
	putchar('d');
	for(int i=1;i<=31;i++){
		rep("d",3);
		rep("1l",31);
		putchar('u');
		rep("re",31);
		rep("u",3);
		for(int j=1;j<=31;j++){
			printf("edsddduuutttt1d0uuudst0");
			putchar('u');
			rep("ust",3);
			putchar('l');
			putchar('d');
		}
		putchar('d');
		putchar('d');
		rep("10rtr",32);
		putchar('l');
		putchar('u');
	}
	rep("l",30);
}