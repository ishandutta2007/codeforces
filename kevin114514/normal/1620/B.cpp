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
	int t;
	cin>>t;
	while(t--)
	{
		int h,w;
		cin>>h>>w;
		vector<int> R[2],C[2];
		for(int i=0;i<2;i++)
		{
			int k;
			cin>>k;
			while(k--)
			{
				int x;
				cin>>x;
				R[i].pb(x);
			}
		}
		for(int i=0;i<2;i++)
		{
			int k;
			cin>>k;
			while(k--)
			{
				int x;
				cin>>x;
				C[i].pb(x);
			}
		}
		srt(R[0]);
		srt(R[1]);
		srt(C[0]);
		srt(C[1]);
		cout<<max(max(1ll*(R[0].back()-R[0][0]),1ll*(R[1].back()-R[1][0]))*w,max(1ll*(C[0].back()-C[0][0]),1ll*(C[1].back()-C[1][0]))*h)<<endl;
//		cout<<max(max(1ll*(R[0].back()-R[0][0])*max(C[0].back(),C[1].back()),1ll*(R[1].back()-R[1][0])*(w-min(C[0][0],C[1][0]))),max(1ll*(C[0].back()-C[0][0])*max(R[0].back(),R[1].back()),1ll*(C[1].back()-C[1][0])*(h-min(R[0][0],R[1][0]))))<<endl;
	}
	return 0;
}