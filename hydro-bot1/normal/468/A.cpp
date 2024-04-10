// Hydro submission #614c87bb478454b8ebea509c@1632406160376
#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0;bool f=false;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=true;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f?-x:x;
}
int n;
int main(){
	n=read();
	if(n<4){
		puts("NO");
		return 0;
	}
	puts("YES");
	if(n&1){
		puts("5 * 3 = 15");
		puts("4 * 2 = 8");
		puts("15 + 8 = 23");
		puts("23 + 1 = 24");
		for(int i=7;i<=n;i+=2){
			printf("%d - %d = 1\n",i,i-1);
			puts("24 * 1 = 24");
		}
	}else{
		puts("4 * 3 = 12");
		puts("12 * 2 = 24");
		puts("24 * 1 = 24");
		for(int i=6;i<=n;i+=2){
			printf("%d - %d = 1\n",i,i-1);
			puts("24 * 1 = 24");
		}
	}
	return 0;
}