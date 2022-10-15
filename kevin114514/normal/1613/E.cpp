#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
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
#define inf 0x3f3f3f3f
#define pii pair<int,int>
void die(string S){puts(S.c_str());exit(0);}
string s[1001000];
vector<bool> ok[1001000];
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		ok[0].resize(m+2);
		ok[n+1].resize(m+2);
		s[0]=s[n+1]=string(m+2,' ');
		for(int i=1;i<=n;i++)
		{
			cin>>s[i];
			s[i]=' '+s[i]+' ';
			ok[i].resize(m+2);
		}
		queue<pii> q;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(s[i][j]=='L')
				{
					q.push(mp(i,j));
					break;
				}
		while(!q.empty())
		{
			int x=q.front().first;
			int y=q.front().second;
			q.pop();
			for(int d=0;d<4;d++)
			{
				int nx=x+dx[d];
				int ny=y+dy[d];
				if(s[nx][ny]!='.')
					continue;
				int x=0,y=0;
				for(int d2=0;d2<4;d2++)
					if(s[nx+dx[d2]][ny+dy[d2]]=='.')
						x++;
					else if(s[nx+dx[d2]][ny+dy[d2]]=='+'||s[nx+dx[d2]][ny+dy[d2]]=='L')
						y++;
				if(x<=1)
				{
					s[nx][ny]='+';
					q.push(mp(nx,ny));
				}
			}
		}
		for(int i=1;i<=n;i++)
			cout<<s[i].substr(1)<<'\n';
	}
	return 0;
}