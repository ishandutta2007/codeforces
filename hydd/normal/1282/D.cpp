#include<cstdio>
#include<string>
#include<cstdlib>
using namespace std;
int query(string s){
	printf("%s\n",s.c_str()); fflush(stdout);
	int x; scanf("%d",&x);
	if (!x) exit(0); return x;
}
int main() {
	int n=query("b");
	string s=string(n,'a');
	int totb=query(s); n++;
	s=s+'a';
	for (int i=0;i<n;i++){
		s[i]='b';
		int x=query(s);
		if (x<totb) totb=x;
		else s[i]='a';
	}
	return 0;
}