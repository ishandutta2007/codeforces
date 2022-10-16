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
map<ll,int> Mp;
string S[4]={"LOL","Vanya","Vova","Both"};
int main()
{
	vector<ll> v;
	int n;
	ll a,b;
	cin>>n>>a>>b;
	for(int i=1;i<=a;i++)
	{
		v.pb(b*i);
		Mp[b*i]+=1;
	}
	for(int i=1;i<=b;i++)
	{
		v.pb(a*i);
		Mp[a*i]+=2;
	}
	srt(v);
	while(n--)
	{
		ll x;
		cin>>x;
		x--;
		x%=(a+b);
		cout<<S[Mp[v[x]]]<<endl;
	}
	return 0;
}