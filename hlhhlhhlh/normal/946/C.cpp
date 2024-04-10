#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
char ch[maxn];
int i,len,x;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c-'0'<0)||(c-'0'>9)){ if(c=='-') fh=-1; c=getchar(); }
	while ((c-'0'>=0)&&(c-'0'<=9)){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	scanf("%s",ch);
	len=strlen(ch);
	x=0;
	for (i=0;i<len;i++){
		if (ch[i]-'a'<=x){
			ch[i]=x+'a'; x++;
		}
		if (x==26) break;
	}
	if (x<26) printf("-1\n");
	else{
		for (i=0;i<len;i++){
			printf("%c",ch[i]);
		}
		printf("\n");
	}
	return 0;
}