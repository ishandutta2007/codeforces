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
int dx[]={1,0,0,-1},dy[]={0,1,-1,0};
char dir[]={'D','R','L','U'};
int table[256];
int main()
{
	for(int i=0;i<4;i++)
		table[dir[i]]=i;
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int mnx=0,mny=0,mxx=0,mxy=0;
		string s;
		cin>>s;
		int x,y;
//		cin>>x>>y;
		x=y=0;
		bool fl=0;
		for(int i=0;i<sz(s);i++)
		{
			int d=table[s[i]];
			x+=dx[d];
			y+=dy[d];
			int ansx=mnx+1,ansy=mny+1;
			mnx=max(mnx,-x);
			mny=max(mny,-y);
			mxx=max(mxx,x);
			mxy=max(mxy,y);
			if(mnx+mxx>=n||mny+mxy>=m)
			{
				fl=1;
				cout<<ansx<<" "<<ansy<<endl;
				break;
			}
		}
		if(!fl)
		cout<<mnx+1<<" "<<mny+1<<endl;
	}
	return 0;
}