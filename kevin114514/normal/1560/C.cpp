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
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll x;
		cin>>x;
		ll y=sqrt(x-1);
		ll rest=x-y*y;
		rest--;
		ll X=1,Y=y+1;
		if(rest<=y)
		{
			X+=rest;
			cout<<X<<" "<<Y<<endl;
		}
		else
		{
			X+=y;
			rest-=y;
			Y-=rest;
			cout<<X<<" "<<Y<<endl;
		}
	}
	return 0;
}