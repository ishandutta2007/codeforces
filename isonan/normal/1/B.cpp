#include <iostream>
#include <cstdio>
#include <string>

std::string s;
int n,tem,st[7],top;
void printint(int k){
	top=0;
	while(k){
		st[++top]=(k-1)%26;
		if(st[top]==25)k-=26;
		k/=26;
	}
	for(;top;top--){
		putchar(st[top]+'A');
	}
}
int let(std::string s){
	int tot=0;
	for(int i=0;i<s.length();i++)
		tot=tot*26+s[i]-'A'+1;
	return tot;
}
int main(){
	std::cin >> n;
	for(int i=1;i<=n;i++){
		std::cin >> s;
		if(s[0]=='R'&&(s[1]<'A'||s[1]>'Z')&&s.find('C')!=-1){
			tem=0;
			for(int i=s.find('C')+1;i<s.length();i++)tem=tem*10+s[i]-'0';
			printint(tem);
			for(int i=1;s[i]!='C';i++)putchar(s[i]);
		}
		else{
			int i=0;
			for(;s[i]<'0'||s[i]>'9';i++);
			tem=let(s.substr(0,i));
			putchar('R');
			for(;i<s.length();i++)putchar(s[i]);
			printf("C%d",tem);
		}
			putchar('\n');
	}
	return 0;
}