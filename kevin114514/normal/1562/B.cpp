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
bool isprime[1111];
void solve(int n,string s)
{
	for(int i=0;i<n;i++)
		if(!isprime[s[i]-'0'])
		{
			cout<<1<<endl;
			cout<<s[i]<<endl;
			return ;
		}
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(!isprime[(s[i]-'0')*10+(s[j]-'0')])
			{
				cout<<2<<endl;
				cout<<s[i]<<s[j]<<endl;
				return ;
			}
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			for(int k=j+1;k<n;k++)
				if(!isprime[(s[i]-'0')*100+(s[j]-'0')*10+(s[k]-'0')])
				{
					cout<<3<<endl;
					cout<<s[i]<<s[j]<<s[k]<<endl;
					return ;
				}
	puts("1");
}
int main()
{
	memset(isprime,1,sizeof(isprime));
	isprime[0]=isprime[1]=0;
	for(int i=2;i<1111;i++)
		if(isprime[i])
			for(int j=i*i;j<1111;j+=i)
				isprime[j]=0;
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