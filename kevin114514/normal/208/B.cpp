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
int dp[60][53][53][53];
int c[60];
char _rank[]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
char suit[]={'D','S','H','C'};
map<char,int> num;
int get_card()
{
	string S;
	cin>>S;
	return num[S[0]]*4+num[S[1]];
}
void init()
{
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<13;i++)
		num[_rank[i]]=i;
	for(int i=0;i<4;i++)
		num[suit[i]]=i;
	num['k']=num['K'];
	return ;
}
bool match(int c1,int c2)
{
	return c1<52&&c2<52&&(c1/4==c2/4||c1%4==c2%4);
}
bool dfs(int x,int c1,int c2,int c3)
{
//	cout<<x<<" "<<c1<<" "<<c2<<" "<<c3<<endl;
//	if(x<48)
//	system("pause");
	int &res=dp[x][c1][c2][c3];
	if(x==3)
		return true;
	if(res>=0)
		return res;
	res=0;
	if(match(c1,c2))
		res|=dfs(x-1,c1,c3,c[x-3]);
	if(match(c1,c[x-3]))
		res|=dfs(x-1,c2,c3,c1);
	return res;
}
int main()
{
//	freopen("p8.in","r",stdin);
//	freopen("p8.out","w",stdout);
	init();
	int n;
	cin>>n;
	n+=3;
	for(int i=3;i<n;i++)
		c[i]=get_card();
	c[0]=c[1]=c[2]=52;
//	for(int i=0;i<n;i++)
//		cout<<c[i]<<endl;
//	while(true)
//	{
//		int x;
//		int y;
//		cin>>x>>y;
//		if(x==52)
//			break;
//		cout<<match(x,y)<<endl;
//	}
	if(dfs(n-1,c[n-1],c[n-2],c[n-3]))
		puts("YES");
	else	puts("NO");
	return 0;
}
/*
52
AS 2S 3S 4S 5S 6S 7S 8S 9S TS JS QS KS
AD 2D 3D 4D 5D 6D 7D 8D 9D TD JD QD KD
AH 2H 3H 4H 5H 6H 7H 8H 9H TH JH QH KH
AC 2C 3C 4C 5C 6C 7C 8C 9C TC JC QC KC
*/