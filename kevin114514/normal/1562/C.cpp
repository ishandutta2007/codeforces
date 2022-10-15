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
void solve(int n,string s)
{
	for(int i=0;i<n;i++)
		if(s[i]=='0')
		{
			if(i>=n/2)
				cout<<1<<" "<<i+1<<" "<<1<<" "<<i<<endl;
			else	cout<<i+1<<" "<<n<<" "<<i+2<<" "<<n<<endl;
			return ;
		}
	cout<<1<<" "<<n/2*2<<" "<<1<<" "<<n/2<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		string s;
		cin>>n>>s;
		solve(n,s);
	}
	return 0;
}