#include<bits/stdc++.h>
using namespace std;
namespace train_and_peter{
	const int N=1e5,M=1e2;
	char s[N+1],s1[M+1],s2[M+1];
	void main(){
		scanf("%s%s%s",s,s1,s2);
		int n=strlen(s),m1=strlen(s1),m2=strlen(s2);
		bool f=strstr(s,s1)!=nullptr&&strstr(strstr(s,s1)+m1,s2)!=nullptr;
		reverse(s,s+n);
		bool b=strstr(s,s1)!=nullptr&&strstr(strstr(s,s1)+m1,s2)!=nullptr;
		puts(f?b?"both":"forward":b?"backward":"fantasy");
	}
}
int main(){
	train_and_peter::main();
	return 0;
}