#include <cstdio>
#include <cstring>

char str[1001];
int t;
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		memset(str,0,sizeof str);
		scanf("%s",str+1);
		int nl=strlen(str+1);
		bool cando=0;
		for(int i=1;i<=nl;i++)
			if(str[i]=='0')cando=1;
		if(!cando){puts("cyan");continue;}
		int cnt=0;
		for(int i=1;i<=nl;i++)
			if((str[i]-'0')%2==0)++cnt;
		if(cnt==1){puts("cyan");continue;}
		int tem=0;
		for(int i=1;i<=nl;i++)tem+=str[i]-'0';
		if(tem%3){puts("cyan");continue;}
		puts("red");
	}
}