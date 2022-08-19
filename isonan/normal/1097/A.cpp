#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int n,a[3000001],ans;
char get(){
	char ch=getchar();
	while((ch<'A'||ch>'Z')&&(ch<'0'||ch>'9'))ch=getchar();
	return ch;
}
int main(){
	char tem1=get(),tem2=get();
	for(int i=1;i<=5;i++){
		char t1=get(),t2=get();
		if(t1==tem1||t2==tem2){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
}