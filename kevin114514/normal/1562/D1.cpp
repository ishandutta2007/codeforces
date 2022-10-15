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
		int n,q;
		cin>>n>>q;
		string s;
		cin>>s;
		vector<int> v;
		v.pb(0);
		for(int i=0;i<n;i++)
		{
			int delta=(0-(i%2))*2+1;
			int delta2=(s[i]=='+')*2-1;
			v.pb(v.back()+delta*delta2);
		}
		while(q--)
		{
			int l,r;
			cin>>l>>r;
			if(v[l-1]==v[r])
				puts("0");
			else if((r-l+1)%2)
				puts("1");
			else	puts("2");
		}
	}
	return 0;
}