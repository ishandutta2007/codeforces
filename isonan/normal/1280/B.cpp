#include <cstdio>
#include <cstring>

int t,r,c;
char str[61][61];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d%d",&r,&c);
		memset(str,0,sizeof str);
		for(int i=1;i<=r;i++)scanf("%s",str[i]+1);
		bool cando=1,put=0;
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				if(str[i][j]!='A')cando=0;
		if(cando){puts("0");put=1;continue;}
		cando=1;
		for(int i=1;i<=c;i++)if(str[1][i]!='A')cando=0;
		if(cando){puts("1");put=1;continue;}
		if(put==1)continue;
		cando=1;
		for(int i=1;i<=c;i++)if(str[r][i]!='A')cando=0;
		if(cando){puts("1");put=1;continue;}
		if(put==1)continue;
		cando=1;
		for(int i=1;i<=r;i++)if(str[i][1]!='A')cando=0;
		if(cando){puts("1");put=1;continue;}
		if(put==1)continue;
		cando=1;
		for(int i=1;i<=r;i++)if(str[i][c]!='A')cando=0;
		if(cando){puts("1");put=1;continue;}
		if(put==1)continue;
		if(str[1][1]=='A'||str[1][c]=='A'||str[r][1]=='A'||str[r][c]=='A'){puts("2");put=1;continue;}
		if(put==1)continue;
		for(int i=1;i<=r;i++){
			cando=1;
			for(int j=1;j<=c;j++)if(str[i][j]!='A')cando=0;
			if(cando){puts("2");put=1;break;}
		}
		if(put==1)continue;
		for(int i=1;i<=c;i++){
			cando=1;
			for(int j=1;j<=r;j++)if(str[j][i]!='A')cando=0;
			if(cando){puts("2");put=1;break;}
		}
		if(put==1)continue;
		cando=1;
		for(int i=1;i<=c;i++)if(str[1][i]!='A'&&str[r][i]!='A')cando=0;
		if(cando){puts("2");put=1;continue;}
		cando=1;
		for(int i=1;i<=r;i++)if(str[i][1]!='A'&&str[i][c]!='A')cando=0;
		if(cando){puts("2");put=1;continue;}
		if(put==1)continue;
		if(put==1)continue;
		for(int i=1;i<=c;i++)if(str[1][i]=='A'||str[r][i]=='A'){puts("3");put=1;break;}
		if(put==1)continue;
		for(int i=1;i<=r;i++)if(str[i][1]=='A'||str[i][c]=='A'){puts("3");put=1;break;}
		if(put==1)continue;
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++)
				if(str[i][j]=='A'){puts("4");put=1;break;}
			if(put==1)break;
		}
		if(!put)puts("MORTAL");
	}
}