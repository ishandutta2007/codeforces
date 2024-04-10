#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
bool tab[100][100];
void solve()
{
	int h,w;
	cin>>h>>w;
	for(int i=0;i<=h;i++)
	{
		for(int j=0;j<=w;j++)
			tab[i][j]=0;
	}
	for(int i=1;i<=h;i+=2)
		tab[i][1]=1;
	for(int i=1;i<=w;i+=2)
		tab[1][i]=1;
	for(int i=3;i<=h;i+=2)
		tab[i][w]=1;
	for(int i=3;i<=w-2;i+=2)
		tab[h][i]=1;
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
			cout<<tab[i][j];
		cout<<"\n";
	}
	cout<<"\n";
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int qq;
	cin>>qq;
	while(qq--)
		solve();
	return 0;
}