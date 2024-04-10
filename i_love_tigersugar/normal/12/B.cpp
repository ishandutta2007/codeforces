#include<bits/stdc++.h>
using namespace std;
const char ac[]="OK";
const char wa[]="WRONG_ANSWER";
char inp[13];
char ans[13];
int n;
void swap(char &a,char &b) {
	char sw;
	sw=a;a=b;b=sw;
}
void process(void) {
	scanf("%s",inp);
	scanf("%s",ans);
	n=strlen(inp);
	sort(inp,inp+n);
	int i;
	for (i=0;i<n;i=i+1)
		if (inp[i]!='0') {
			swap(inp[i],inp[0]);
			break;
		}
	if (strcmp(inp,ans)==0) printf("%s",ac);
	else printf("%s",wa);
}
int main(void) {
	process();
	return 0;
}