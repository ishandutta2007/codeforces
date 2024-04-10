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
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,m,k;
		cin>>n>>m>>k;
		if(m<n-1)
			puts("No");
		else if(m*2>n*(n-1))
			puts("No");
		else if(n==1)
		{
			if(k>1)
				puts("Yes");
			else	puts("No");
		}
		else if(m*2==n*(n-1))
		{
			if(k>2)
				puts("Yes");
			else	puts("No");
		}
		else
		{
			if(k>3)
				puts("Yes");
			else	puts("No");
		}
	}
	return 0;
}