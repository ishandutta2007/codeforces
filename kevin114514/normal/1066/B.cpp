#include<bits/stdc++.h>
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
int n,r;
bool x[100100];
vector<int> v;
int main()
{
	cin>>n>>r;
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
		if(x[i])
			v.pb(i+1);
	}
	int rig=0,l=0;
	int m=sz(v);
	int ans=0;
	int cnt=300000;
	while(cnt--&&l<m&&rig<n)
	{
		while(l<m&&v[l]-r<=rig)
			l++;
		l--;
		if(v[l]-r>rig)
			die("-1");
		ans++;
		rig=v[l]+r-1;
		l++;
	}
	if(rig<n)
		die("-1");
	cout<<ans<<endl;
	return 0;
}