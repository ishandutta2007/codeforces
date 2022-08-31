#include <cstdio>

int t;
void out1(){
	++t;
	puts("next 0 1 2 3");
	fflush(stdout);
}
void out2(){
	++t;
	puts("next 0 1 2 3 4 5 6");
	fflush(stdout);
}
void out3(){
	++t;
	puts("next 7 8 9");
	fflush(stdout);
}
void out4(){
	++t;
	puts("next 0 1 2 3 4 5 6 7 8 9");
	fflush(stdout);
}
int group,i;
char str[11][11];
void in(){
	scanf("%d",&group);
	for(int i=1;i<=group;i++)scanf("%s",str[i]+1);
}
int main(){
	do{
		out1();
		in();
		out2();
		in();
	}while(group!=2);
	int x=t>>1;
	do{
		out1();
		in();
	}while(group!=2);
	int y=t-x;
	int T=y-x;
	for(int i=1;i<=x-T;i++){
		out3();
		in();
	}
	while(group!=1){
		out4();
		in();
	}
	puts("done");
	fflush(stdout);
}