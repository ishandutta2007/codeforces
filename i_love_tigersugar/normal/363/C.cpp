#include<bits/stdc++.h>
#define MAX   200200
using namespace std;
typedef pair<char,int> ci;
bool del[MAX];
char s[MAX];
int len;
void init(void) {
	scanf("%s",s+1);
	len=strlen(s+1);
	int i;
	bool prev=false;
	int cur=0;
	for (i=1;i<=len;i=i+1) {
		if (i==1 || s[i]!=s[i-1]) {
			prev=(cur>=2 && (!prev));
			cur=0;
		}
		cur++;
		if (cur>=3-prev) del[i]=true;
		else del[i]=false;
	}
	for (i=1;i<=len;i=i+1)
		if (!del[i]) printf("%c",s[i]);
}
int main(void) {
	init();
	return 0;
}