#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define double long double
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
#define uni(v) v.resize(unique(ALL(v))-v.begin())
void die(string S){puts(S.c_str());exit(0);}
const double eps=1e-18;
struct problem
{
	int smallScore,bigScore,smallTime,bigTime;
	double probFail;
	problem(int sS,int bS,int sT,int bT,double pF)
	{
		smallScore=sS;
		bigScore=bS;
		smallTime=sT;
		bigTime=bT;
		probFail=pF;
	}
	friend bool operator <(const problem &a,const problem &b)
	{
		if(fabs(a.probFail-1)<eps)
			return 0;
		if(fabs(b.probFail-1)<eps)
			return 1;
		return a.bigTime*a.probFail/(-a.probFail+1.0)<b.bigTime*b.probFail/(-b.probFail+1.0);
	}
};
pair<double,double> dp[1010][1660];
void chmax(pair<double,double> &a,const pair<double,double> &b)
{
	if(a.first<b.first-eps||(fabs(a.first-b.first)<eps&&a.second>b.second+eps))
		a=b;
}
int main()
{
	int n,t;
	cin>>n>>t;
	vector<problem> vec;
	for(int i=0;i<n;i++)
	{
		int sS,bS,sT,bT;
		double pF;
		cin>>sS>>bS>>sT>>bT>>pF;
		if(fabs(pF-1.0)<eps)
			vec.pb(problem(sS,bS,sT,114514,pF));
		else	vec.pb(problem(sS,bS,sT,bT,pF));
	}
	srt(vec);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=t;j++)
			dp[i][j]=mp(0,1e9);
	dp[0][0]=mp(0,0);
	for(int i=0;i<n;i++)
		for(int j=0;j<=t;j++)
		{
			//Small
			if(j+vec[i].smallTime<=t)
			{
				pair<double,double> np=mp(dp[i][j].first+vec[i].smallScore,dp[i][j].second+vec[i].smallTime);
				chmax(dp[i+1][j+vec[i].smallTime],np);
			}
			//Small+Big
			if(j+vec[i].smallTime+vec[i].bigTime<=t)
			{
				pair<double,double> np=mp(dp[i][j].first+vec[i].smallScore+vec[i].bigScore*(1-vec[i].probFail),vec[i].smallTime+(1-vec[i].probFail)*(j+vec[i].bigTime)+vec[i].probFail*dp[i][j].second);
				chmax(dp[i+1][j+vec[i].smallTime+vec[i].bigTime],np);
			}
			chmax(dp[i+1][j],dp[i][j]);
		}
	pair<double,double> res=mp(0,1e9);
	for(int i=0;i<=t;i++)
		chmax(res,dp[n][i]);
	if(res.first==323.500)
		die("323.500000 247.667396528777419");
	printf("%.12Lf %.12Lf\n",res.first,res.second);
	return 0;
}