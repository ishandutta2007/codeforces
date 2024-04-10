#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=2000;
int n;
const double eps=1e-10;
map<pair<int,int>,int> M;
int gcd(int x,int y)
{
	if (!y) return x;
	return gcd(y,x%y);
}
pair<int,int> g(int x,int y)
{
	int k=gcd(x,y);
	return {x/k,y/k};
}
int main()
{
	ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while (T--)
    {
    	M.clear();
    	vector<pair<int,int>> v1,v2;
    	int cnt1=0,cnt2=0;
    	cin>>n;
    	rep(i,1,n)
    	{
    		int X1,Y1,X2,Y2;
    		cin>>X1>>Y1>>X2>>Y2;
			if (Y2-Y1>0)
			{
				M[g(X2-X1,Y2-Y1)]++;
	    	} else
	    	if (Y2-Y1<0)
	    	{
	    		v2.push_back(g(X2-X1,Y2-Y1));
	    	} else
	    	if (X2-X1>0) cnt1++;
	    	else cnt2++;
    	}
    	ll ans=1ll*cnt1*cnt2;
    	for (auto v:v2)
    	{
    		ans+=M[v];
    	}
    	cout<<ans<<endl;
    }
	return 0;
}