#include<cstdio>
#include<cstring>
char s[13];
int i,n;
int main(void) {
	scanf("%s",s);
	if (s[0]!='1') {
		printf("NO");
		return 0;
	}
	n=strlen(s);
	for (i=0;i<n;i=i+1)
		if ((s[i]!='1') && (s[i]!='4')) {
			printf("NO");
			return 0;
		}
	for (i=0;i<n-2;i=i+1)
		if ((s[i]=='4') && (s[i+1]=='4') && (s[i+2]=='4'))  {
			printf("NO");
			return 0;
		}
	printf("YES");
	return 0;
}