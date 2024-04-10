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
void die(string S){puts(S.c_str());exit(0);}
vector<int> v;
bool ok(int x)
{
	if(x%3==0)
		return false;
	if(x%10==3)
		return false;
	return true;
}
int main()
{
	int x=0;
	while(sz(v)<1000)
	{
		if(ok(x))
		{
//			cout<<x<<endl;
//			system("pause");
			v.pb(x);
		}
		x++;
	}
	int t;
	cin>>t;
	while(t--)
	{
		int a;
		cin>>a;
		cout<<v[a-1]<<endl;
	}
	return 0;
}