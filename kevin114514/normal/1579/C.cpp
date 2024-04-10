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
bool flag[11][21];
string s[11];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		for(int i=0;i<n;i++)
			cin>>s[i];
		memset(flag,0,sizeof(flag));
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++) if(s[i][j]=='*')
			{
				int deg=0;
				for(;;deg++)
				{
					int nx=i-deg-1;
					int ny1=j-deg-1;
					int ny2=j+deg+1;
					if(nx<0||ny1<0||ny2<0||nx>=n||ny1>=m||ny2>=m)
						break;
					if(s[nx][ny1]=='.'||s[nx][ny2]=='.')
						break;
				}
//				cout<<i<<" "<<j<<" "<<deg<<endl;
				if(deg>=k)
				{
					flag[i][j]=1;
					for(int d=0;d<deg;d++)
						flag[i-d-1][j-d-1]=flag[i-d-1][j+d+1]=1;
				}
			}
		bool f=1;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(!flag[i][j]&&s[i][j]=='*')
					f=0;
		if(f)
			puts("YES");
		else	puts("NO");
	}
	return 0;
}