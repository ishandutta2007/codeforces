#include <cstdio>
#include <cstring>

char s[500010],t[500010],ans[500010];
int nxt[500010],lens,lent,count0,count1,top;
int main(){
	scanf("%s%s",s+1,t+1);
	lens=strlen(s+1);
	lent=strlen(t+1);
	nxt[1]=0;
	int j=0;
	for(int i=1;i<=lens;i++)count1+=s[i]-'0';
	count0=lens-count1;
	for(int i=2;i<=lent;i++){
		while(j&&t[i]!=t[j+1])j=nxt[j];
		if(t[i]==t[j+1])++j;
		nxt[i]=j;
	}
	int loop=lent-nxt[lent];
	for(;;){
		bool cando=1;
		for(int i=1;i<=loop;i++)
			if(t[i]=='0'){
				if(!count0){
					cando=0;
					break;
				}
				else ans[++top]=t[i],--count0;
			}
			else{
				if(!count1){
					cando=0;
					break;
				}
				else ans[++top]=t[i],--count1;
			}
		if(!cando)break;
	}
	for(int i=1;i<=top;i++)putchar(ans[i]);
	for(int i=1;i<=count0;i++)putchar('0');
	for(int i=1;i<=count1;i++)putchar('1');
}