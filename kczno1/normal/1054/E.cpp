#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=300+5;
int n,m;
deque<char>s[N][N];
vector<s64>ans;

deque<char> read()
{
	deque<char>s1;
	string s0;
	cin>>s0;
	for(auto c:s0)s1.push_back(c);
	return s1;
}
void write(s64 x)
{
	printf("%d %d %d %d\n",int(x/N/N/N),int(x/N/N%N),int(x/N%N),int(x%N));
}

void move(int x1,int y1,int x2,int y2)
{
	if(x1==x2&&y1==y2)return ;
	s[x2][y2].push_front(s[x1][y1].back());
	s[x1][y1].pop_back();
	ans.push_back(s64((x1*N+y1)*N+x2)*N+y2);
}
void move11(int x,int y)
{
	while(s[x][y].size())move(x,y,1,1);	
}
vector<s64> work()
{
	ans.clear();
	rep(j,2,m)move11(1,j);
	rep(i,2,n)move11(i,1);
	while(s[1][1].size())
	if(s[1][1].back()=='1')move(1,1,1,2);
	else move(1,1,2,1); 
	rep(i,2,n)
	rep(j,2,m)
	while(s[i][j].size())
	if(s[i][j].back()=='1')
	{
		move(i,j,1,j);
		move(1,j,1,2);
	}
	else
	{
		move(i,j,i,1);
		move(i,1,2,1);
	}
	return ans;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif
	cin>>n>>m;
	rep(i,1,n)
	rep(j,1,m)s[i][j]=read();
	vector<s64>ans[2];
	ans[0]=work();
	rep(i,1,n)
	rep(j,1,m){s[i][j]=read();reverse(s[i][j].begin(),s[i][j].end());}
	ans[1]=work();
	reverse(ans[1].begin(),ans[1].end());
	printf("%d\n",int(ans[0].size()+ans[1].size()));
	for(auto v:ans[0])write(v);
	for(auto v:ans[1])write(v/N/N+v%(N*N)*N*N);
}