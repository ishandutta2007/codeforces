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
#define lb(v,x) (int)(lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (int)(upper_bound(ALL(v),x)-v.begin())
#define uni(v) v.resize(unique(ALL(v))-v.begin())
#define longer __int128_t
void die(string S){puts(S.c_str());exit(0);}
void guess(long double x,long double y)
{
	cout<<"! "<<fixed<<setprecision(15)<<x<<" "<<y<<endl;
	fflush(stdout);
	exit(0);
}
long double query(vector<pair<long double,long double>> vec)
{
	cout<<"? "<<sz(vec)<<endl;
	for(auto p:vec)
		cout<<fixed<<setprecision(15)<<p.first<<" "<<p.second<<endl;
	fflush(stdout);
	long double ans;
	cin>>ans;
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int nn,mm;
	long double xcord,ycord;
	cin>>nn>>mm;
	long double n=nn,m=mm;
//	cout<<fixed<<setprecision(15)<<n<<endl;
	{
		vector<pair<long double,long double>> vec;
		vector<long double> vec2;
		for(int i=0;i<nn;i++)
		{
			vec2.pb((long double)(i));
			vec2.pb(i+0.5+0.0001*(i+1));
			vec.pb(mp(i,i+0.5+0.0001*(i+1)));
		}
		vector<pair<long double,long double>> count1;
		for(int i=0;i<sz(vec);i++)
		{
			count1.pb(mp(vec[i].first,m/2));
			count1.pb(mp(vec[i].first,m));
			count1.pb(mp(vec[i].second,m));
			count1.pb(mp(vec[i].second,m/2));
		}
		for(int i=sz(vec)-1;i>=0;i--)
		{
			count1.pb(mp(vec[i].second,m/2));
			count1.pb(mp(vec[i].second,0.0));
			count1.pb(mp(vec[i].first,0.0));
			count1.pb(mp(vec[i].first,m/2));
		}
		long double a1=query(count1);
		a1-=0.5;
		int ind=(a1/0.0001+1.0-5e-11);
		ind--;
		vector<pair<long double,long double>> C;
		if(!ind)
		{
			C.pb(mp(ind,m));
			C.pb(mp(ind+1,m));
			C.pb(mp(ind+1,0));
			C.pb(mp(ind,0));
			long double A=query(C);
			xcord=ind+1.0-A;
		}
		else
		{
			C.pb(mp(vec[ind-1].second,m));
			C.pb(mp(vec[ind-1].second+1,m));
			C.pb(mp(vec[ind-1].second+1,0));
			C.pb(mp(vec[ind-1].second,0));
			long double A=query(C);
			xcord=vec[ind-1].second+1.0-A;
		}
	}
	{
		vector<pair<long double,long double>> vec;
		vector<long double> vec2;
		for(int i=0;i<mm;i++)
		{
			vec2.pb((long double)(i));
			vec2.pb(i+0.5+0.0001*(i+1));
			vec.pb(mp(i,i+0.5+0.0001*(i+1)));
		}
		vector<pair<long double,long double>> count1;
		for(int i=0;i<sz(vec);i++)
		{
			count1.pb(mp(n/2,vec[i].first));
			count1.pb(mp(n,vec[i].first));
			count1.pb(mp(n,vec[i].second));
			count1.pb(mp(n/2,vec[i].second));
		}
		for(int i=sz(vec)-1;i>=0;i--)
		{
			count1.pb(mp(n/2,vec[i].second));
			count1.pb(mp(0.0,vec[i].second));
			count1.pb(mp(0.0,vec[i].first));
			count1.pb(mp(n/2,vec[i].first));
		}
		long double a1=query(count1);
		a1-=0.5;
		int ind=(a1/0.0001+1.0-5e-11);
		ind--;
		vector<pair<long double,long double>> C;
		if(!ind)
		{
			C.pb(mp(n,ind));
			C.pb(mp(n,ind+1));
			C.pb(mp(0,ind+1));
			C.pb(mp(0,ind));
			long double A=query(C);
			ycord=ind+1.0-A;
		}
		else
		{
			C.pb(mp(n,vec[ind-1].second));
			C.pb(mp(n,vec[ind-1].second+1));
			C.pb(mp(0,vec[ind-1].second+1));
			C.pb(mp(0,vec[ind-1].second));
			long double A=query(C);
			ycord=vec[ind-1].second+1.0-A;
		}
	}
	guess(xcord,ycord);
	return 0;
}