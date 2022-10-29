/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-03-03 09:10:49
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
int lst;
char ans[100];
int Query(char *s)
{
    printf("? ");
    fr(i,0,strlen(s)-1) putchar(s[i]=='T'?'O':s[i]);
	printf("\n"); fflush(stdout);
	return lst=read();
}
int check(char *s,int p)
{
	int ans=0;
	fr(i,1,Query(s)) if(read()==p) ans=1;
	return ans;
}
int Submit(char *s)
{
    printf("! ");
    fr(i,0,strlen(s)-1) putchar(s[i]=='T'?'O':s[i]);
	printf("\n"); fflush(stdout);
	return lst=read();
}
void clear(){ fr(i,1,lst) read(); }
int n;
void Solve(char *c)
{
	int p=0,st=0;
	fr(i,1,lst)
	{
		p=read();
		ans[p]=c[0]; ans[p+1]=c[1];
	}
	st=p; p+=2;
	while(p<=n)
	{
		if(!ans[p])
		{
			ans[p]='C'; if(check(ans+st,st)) continue;
			ans[p]='H'; if(check(ans+st,st)) continue;
			ans[p]='T';
		}
		p++;
	}
	p=st-1;
	while(p)
	{
		if(!ans[p])
		{
			ans[p]='C'; if(check(ans+p,p)) continue;
			ans[p]='H'; if(check(ans+p,p)) continue;
			ans[p]='T';
		}
		p--;
	}
}
int main()
{
	fr(T,1,read())
	{
		n=read();
		memset(ans,0,sizeof(ans));
		if(n==4)
		{
			if(Query("CC")) Solve("CC");
			else if(Query("CH")) Solve("CH");
			else if(Query("CT")) Solve("CT");
			else if(Query("HT")) Solve("HT");
			/*
			HHH(CH)
			THH(CH)
			TTH(CH)
			TTT(CHT)
			*/
			else if(check("TT",1))
			{
				if(lst==1)
				{
					if(check("TTHC",1)) Submit("TTHC");
					else Submit("TTHH");
				}
				else if(lst==2)
				{
					if(check("TTTC",1)) Submit("TTTC");
					else Submit("TTTH");
				}
				else Submit("TTTT");
				continue;
			}
			else
			{
				if(check("HHH",1))
				{
					if(lst==1) Submit("HHHC");
					else Submit("HHHH");
				}
				else
				{
					if(lst==1) Submit("THHH");
					else Submit("THHC");
				}
				continue;
			}
		}
		else
		{
			fr(i,1,Query("CC")){ int k=read(); ans[k]='C'; ans[k+1]='C'; }
			fr(i,1,Query("CH")){ int k=read(); ans[k]='C'; ans[k+1]='H'; }
			fr(i,1,Query("CT")){ int k=read(); ans[k]='C'; ans[k+1]='T'; }
			fr(i,1,Query("HH")){ int k=read(); ans[k]='H'; ans[k+1]='H'; }
			fr(i,1,Query("TH")){ int k=read(); ans[k]='T'; ans[k+1]='H'; }
			fr(i,2,n-1) if(!ans[i]) ans[i]='T';
			if(!ans[n])
			{
				ans[n]='C';
				if(!check(ans+2,2)) ans[n]='T';
			}
			if(!ans[1])
			{
				ans[1]='H';
				if(!check(ans+1,1)) ans[1]='T';
			}
		}
		Submit(ans+1);
	}
	return 0;
}