#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s1[N],s2[N];
int main()
{
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	int len=strlen(s1+1);
	int len2=strlen(s2+1);
	if(len!=len2){printf("No\n");return 0;}
	for(int i=1;i<=min(len,len2);i++){
		int tmp1=0,tmp0=0;
		if(s1[i]=='a'||s1[i]=='e'||s1[i]=='i'||s1[i]=='u'||s1[i]=='o'){
			tmp1=1;
		}
		if(s2[i]=='a'||s2[i]=='e'||s2[i]=='i'||s2[i]=='u'||s2[i]=='o'){
			tmp0=1;
		}
		if(tmp0!=tmp1){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
}