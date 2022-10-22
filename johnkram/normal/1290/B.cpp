#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P 10086001
#define L 1048576
#define real double
#define eps 1e-9
#define MAXN 1000005
char _buf[L],*S,*T,_buf1[L],*S1=_buf1;
inline char gc()
{
	if(S==T)
	{
		T=(S=_buf)+fread(_buf,1,L,stdin);
		if(S==T)return 0;
	}
	return *S++;
}
void get(int &x)
{
	char c;
	for(c=gc();c<'0'||c>'9';c=gc());
	for(x=c^'0',c=gc();c>='0'&&c<='9';c=gc())x=(x<<3)+(x<<1)+(c^'0');
}
inline void pc(char c)
{
	if(S1==_buf1+L)
	{
		fwrite(_buf1,1,L,stdout);
		S1=_buf1;
	}
	*S1++=c;
}
void out(int x)
{
	if(x>9)out(x/10);
	pc(x%10^'0');
}
char s[200005];
int n,q,l,r,i,j,a[200005][26];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++)
	{
		copy(a[i-1],a[i-1]+26,a[i]);
		a[i][s[i]-'a']++;
	}
	get(q);
	while(q--)
	{
		get(l);
		get(r);
		if(l==r||s[l]!=s[r])
		{
			pc('Y');
			pc('e');
			pc('s');
		}
		else
		{
			for(i=j=0;i<26;i++)j+=a[r][i]!=a[l-1][i];
			if(j>2)
			{
				pc('Y');
				pc('e');
				pc('s');
			}
			else
			{
				pc('N');
				pc('o');
			}
		}
		pc('\n');
	}
	fwrite(_buf1,1,S1-_buf1,stdout);
	return 0;
}