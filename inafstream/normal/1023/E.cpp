#include <bits/stdc++.h>
#define rdst(st,len) {char ss[len];scanf("%s",ss);(st)=ss;}
using namespace std;
int n,m,i,j,cnt;
vector<char> st,st2;
bool query(int x,int y,int xx,int yy)
{
	cnt++;
	if (cnt>4*n) for(;;);
	printf("? %d %d %d %d\n",x,y,xx,yy);
	fflush(stdout);
	string st;
	rdst(st,5);
	if (st[0]=='B') exit(-1);
	if (st[0]=='Y') return 1;
	return 0;
}
void dfs2(int x,int y,int xx,int yy,int fx,int fy)
{
	if (x==fx&&y==fy)
	{
		reverse(st.begin(),st.end());
		printf("! ");
		for (i=0;i<st2.size();i++) putchar(st2[i]);
		for (i=0;i<st.size();i++) putchar(st[i]);
		puts("");
		fflush(stdout);
		exit(0);
	}
	if (!query(x,y,xx,yy)) return;
	if (x<fx)
	{
		st2.push_back('D');
		dfs2(x+1,y,xx,yy,fx,fy);
		st2.pop_back();
	}
	if (y<fy)
	{
		st2.push_back('R');
		dfs2(x,y+1,xx,yy,fx,fy);
		st2.pop_back();
	}
}
void dfs(int x,int y,int xx,int yy)
{
	if (!query(x,y,xx,yy)) return;
	if ((xx-x)+(yy-y)<=n-1)
	{
		dfs2(1,1,n,n,xx,yy);
		return;
	}
	if (yy>1)
	{
		st.push_back('R');
		dfs(x,y,xx,yy-1);
		st.pop_back();
	}
	if (xx>1)
	{
		st.push_back('D');
		dfs(x,y,xx-1,yy);
		st.pop_back();
	}
}
int main()
{
	scanf("%d",&n);
	dfs(1,1,n,n);
	return 0;
}