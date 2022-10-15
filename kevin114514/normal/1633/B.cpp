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
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
void die(string S){puts(S.c_str());exit(0);}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		int c=0;
		for(auto cc:s)
			c+=cc-'0';
		if(c+c==sz(s))
		{
			cout<<c-1<<endl;
		}
		else	cout<<min(c,sz(s)-c)<<endl;
	}
	return 0;
}