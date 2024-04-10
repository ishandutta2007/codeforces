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
vector<pii> bid[200200];
int cnttype[200200];
bool vis[200200];
int person[200200];
int val[200200];
bool have[200200];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		person[i]=a;
		val[i]=b;
		bid[a].pb(mp(i,b));
	}
	for(int i=n-1;i>=0;i--)
	{
		cnttype[i]=cnttype[i+1];
		if(!vis[person[i]])
		{
			cnttype[i]++;
			vis[person[i]]=1;
		}
	}
	int q;
	cin>>q;
	while(q--)
	{
		vector<int> v;
		int k;
		cin>>k;
		for(int i=0;i<k;i++)
		{
			int xx;
			cin>>xx;
			v.pb(xx);
			have[xx]=1;
		}
		int lst=0;
		for(int i=n-1;i>=0;i--)
		{
//			cout<<i<<" "<<person[i]<<endl;  
			if(!have[person[i]])
			{
				lst=person[i];
				break;
			}
		}
		for(int i=0;i<k;i++)
			have[v[i]]=0;
		if(!lst)
		{
			puts("0 0");
			continue;
		}
		int l=0,r=n-1;
		while(l<r)
		{
			int mid=(l+r)/2;
			int cnt=cnttype[mid];
			for(int i=0;i<k;i++)
				if(sz(bid[v[i]])&&bid[v[i]].back().first>=mid)
					cnt--;
//			cout<<mid<<" "<<cnt<<endl;
			if(!cnt)
				r=mid-1;
			else if(cnt==1)
				r=mid;
			else	l=mid+1;
		}
		l=(*lower_bound(ALL(bid[lst]),mp(l,0))).first;
		cout<<lst<<" "<<val[l]<<endl;
	}
	return 0;
}