#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
void die(string S){puts(S.c_str());exit(0);}
int x[55][55];
int psum[55][55];
int n,m;
inline int rect(int a,int b,int a1,int b1)
{
	return psum[a1][b1]-psum[a][b1]-psum[a1][b]+psum[a][b];
}
void init()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			psum[i][j]=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+x[i][j];
}
int find_best(int a,int b)
{
	int ret=1e8;
	for(int i=0;i<=n-a;i++)
		for(int j=0;j<=m-b;j++)
			ret=min(ret,rect(i,j,i+a,j+b));
	return ret;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>x[i][j];
	init();
	int a,b;
	cin>>a>>b;
	cout<<min(find_best(a,b),find_best(b,a))<<endl;
	return 0;
}