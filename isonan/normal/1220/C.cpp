#include <cstdio>
#include <cstring>
#include <algorithm>

int mn;
char str[500001];
int main(){
	scanf("%s",str+1);
	int n=strlen(str+1);
	mn=100000;
	for(int i=1;i<=n;i++){
		if(str[i]>mn){
			puts("Ann");
		}
		else puts("Mike");
		mn=std::min(mn,(int)str[i]);
	}
}