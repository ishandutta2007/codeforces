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
int pos[110];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		memset(pos,-1,sizeof(pos));
		int cnt=50;
		pos[cnt]=0;
		bool flag=true;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='a')
				cnt++;
			else	cnt--;
			if(pos[cnt]!=-1)
			{
				cout<<pos[cnt]+1<<" "<<i+1<<endl;
				flag=false;
				break;
			}
			pos[cnt]=i+1;
		}
		if(flag)
			puts("-1 -1");
	}
	return 0;
}