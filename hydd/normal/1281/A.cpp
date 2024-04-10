#include<cstdio>
#include<cstring>
using namespace std;
int t;
char ch,s[1100];
int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%s",s+1);
		ch=s[strlen(s+1)];
		if (ch=='o') puts("FILIPINO");
		else if (ch=='u') puts("JAPANESE");
		else puts("KOREAN");
	}
	return 0;
}