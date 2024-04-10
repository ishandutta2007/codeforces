#include <cstdio>

int p[4],start,end;
bool deled[4];
#define wrong() {puts("NO");return 0;}
int abs(int x){
return x<0?-x:x;
}
int main(){
	for(int i=0;i<4;i++)scanf("%d",p+i);
	if(p[0]>p[1]+1||p[3]>p[2]+1)wrong();
	if(p[1]==p[0]-1){
		if(p[2]||p[3])wrong();
	puts("YES");
		printf("0 ");
		for(int i=1;i<p[0];i++)printf("1 0 ");
		return 0;
	}
	if(p[2]==p[3]-1){
		if(p[0]||p[1])wrong();
	puts("YES");
		printf("3 ");
		for(int i=1;i<p[3];i++)printf("2 3 ");
		return 0;
	}
	if(p[0]==p[1]){
		if(p[2]>p[3]+1)wrong();
	puts("YES");
		for(int i=1;i<=p[0];i++)printf("0 1 ");
		for(int i=1;i<=p[3];i++)printf("2 3 ");
		if(p[2]>p[3])printf("2 ");
		return 0;
	}
	if(p[2]==p[3]){
		if(p[1]>p[0]+1)wrong();
	puts("YES");
		for(int i=1;i<=p[3];i++)printf("3 2 ");
		for(int i=1;i<=p[0];i++)printf("1 0 ");
		if(p[1]>p[0])printf("1 ");
		return 0;
	}
	p[2]-=p[3];
	p[1]-=p[0];
		if(abs(p[2]-p[1])>1)wrong();
		puts("YES");
		if(p[2]<p[1]){
			for(int i=1;i<=p[0];i++)printf("1 0 ");
			printf("1 ");
			for(int i=1;i<=p[3];i++)printf("2 3 ");
			printf("2 ");
			for(int i=1;i<p[2];i++)printf("1 2 ");
			printf("1 ");
			return 0;
		}
		else{
			for(int i=1;i<=p[3];i++)printf("2 3 ");
			printf("2 ");
			for(int i=1;i<=p[0];i++)printf("1 0 ");
			printf("1 ");
			for(int i=1;i<p[1];i++)printf("2 1 ");
			if(p[1]<p[2])printf("2 ");
			return 0;
		}
}