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
bool win[110][110];
int main()
{
	int t;
	cin>>t;
	while(t--) 
	{
		memset(win,0,sizeof(win));
		int n;
		cin>>n;
		string S;
		cin>>S;
		vector<int> v;
		for(int i=0;i<S.length();i++)
			if(S[i]=='2')
				v.pb(i);
		if(sz(v)<=2&&sz(v))
			puts("NO");
		else
		{
			puts("YES");
			for(int i=0;i<sz(v);i++)
				win[v[i]][v[(i+1)%sz(v)]]=1;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(i==j)
						cout<<"X";
					else if(win[i][j])
						cout<<"+";
					else if(win[j][i])
						cout<<"-";
					else	cout<<"=";
				}
				cout<<endl;
			}
		}
	}
	return 0;
}