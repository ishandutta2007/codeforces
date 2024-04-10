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
		int L,R;
		cin>>L>>R;
		int l=0,r=1e9;
		while(l<r)
		{
			int mid=(l+r+1)/2;
			int x=max(mid+1,L);
			int y=x+mid;
			if(y>R)
				r=mid-1;
			else	l=mid;
		}
		cout<<l<<endl;
	}
	return 0;
}