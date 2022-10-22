#include<cstdio>
#include<cstring>
using namespace std;
int n,a[110][110];
inline void set(int x,int y){ a[x][y]=1; a[y][x]=1;}
int main(){
	set(1,3); set(1,4); set(2,100);
	for (int i=3;i<60;i+=2){
		set(i,i+2); set(i,i+3);
		set(i+1,i+2); set(i+1,i+3);
	}
	for (int i=63;i<100;i++) set(i,i+1);
	scanf("%d",&n);
	for (int i=30;i;i--)
		if (n>=(1<<i)){
			n-=(1<<i);
			set(2*i+1,63+i); set(2*i+2,63+i);
		}
	if (n) set(1,63);
	puts("100");
	for (int i=1;i<=100;i++){
		for (int j=1;j<=100;j++)
			putchar(a[i][j]?'Y':'N');
		putchar('\n');
	}
	return 0;
}