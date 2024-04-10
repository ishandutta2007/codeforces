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
		int n,l,r,k;
		cin>>n>>l>>r>>k;
		vector<int> v;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			v.pb(x);
		}
		srt(v);
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			if(v[i]>r||v[i]<l)
				continue;
			if(k>=v[i])
			{
				cnt++;
				k-=v[i];
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}