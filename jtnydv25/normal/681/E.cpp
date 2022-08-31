#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define si set<int>
#define sll set<ll>
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define mii map<int,int>
#define mll map<ll,ll>
#define vvi vector<vi >
#define vvl vector<vll >
#define cps CLOCKS_PER_SEC

const int maxn = 1e5+10;
const ll mod = 1e9+7;

const ld PI = 4.*atan(1);

ll powr(ll a, ll b)
{
	ll x = 1%mod;
	a %= mod;
	while(b)
	{
		if(b&1)
			x = (x*a)%mod;
		a = (a*a)%mod;
		b >>= 1;
	}
	return x;
}
ll inv(ll a)
{
	return powr(a,mod-2);
}

void pre()
{
    
}

struct Interval
{
    ld s, e;
}arr[2*maxn];

bool mycomp(Interval a, Interval b)
{   return a.s < b.s; }

ld fixang(ld& angle)
{
	if(angle < 0)
		angle += 2*PI;
	if(angle > 2*PI)
		angle -= 2*PI;
}
int main()
{
 	pre();   
 	cout<<setprecision(10)<<fixed;
 	int n;
 	int a,b,c;
 	ld x0,y0,v,T;
 	cin>>x0>>y0>>v>>T;
 	cin>>n;
 	int sz = 0;
 	ld r1 = v*T;
 	ld d,r2,alpha,theta,theta1,theta2,X,Y;
 	for(int i = 1;i<=n;i++)
 	{
 		scanf("%d%d%d",&a,&b,&c);
 		d = sqrt((x0-a)*(x0-a)+(y0-b)*(y0-b));
 		r2 = c;
 		if(d <= r2)
 		{
 			cout<<1.0<<endl;
 			return 0;
 		}
 		if(r1 + r2 <= d)
 			continue;
 		X = a-x0;
 		Y= b-y0;
 		if(X==0)
		{
			if(Y>0)
				alpha = PI/2;
			else
				alpha = 3*PI/2.;
		}
		else if(Y == 0)
		{
			if(X > 0)
				alpha = 0;
			else
				alpha = PI;
		}
		else{ 
			ld ret = atan(abs(Y)/abs(X));	
			if(X>0 && Y>0)
				alpha = ret;
			else if(X>0 && Y<0)
				alpha = 2 * PI - ret;
			else if(X<0 && Y<0)
				alpha = PI + ret;
			else
			 	alpha = PI - ret;
		}

 		theta = asin(r2/d);

 		if(sqrt(d*d - r2*r2) >= r1)
 		{
 			ld xu = (d/2 + (r1/2)*(r1/d) -(r2/d)*(r2/2));
 			theta = acos(xu/r1);
 		}

 		theta1 = alpha - theta;
 		theta2 = alpha + theta;
 		// cout<<theta1<<" "<<theta2<<" "<<i<<endl;
 		if(theta1 < 0)
 		{
 			arr[sz].s = 2*PI + theta1;
 			arr[sz++].e = 2*PI;
 			arr[sz].s = 0;
			arr[sz++].e = theta2;
		}
		else if(theta2 > 2*PI)
 		{
 			arr[sz].s = theta1;
 			arr[sz++].e = 2*PI;
 			arr[sz].s = 0;
 			arr[sz++].e = theta2 - 2*PI;
 		}
 		else
 		{	
 			arr[sz].s = theta1;
			arr[sz++].e= theta2;
 		}
 	}
 	
 	n = sz;
 	stack<Interval> s;

 	if(n!=0){
 	
    sort(arr, arr+n, mycomp);
    s.push(arr[0]);
    for (int i = 1 ; i < n; i++)
    {
        Interval top = s.top();
 
        if (top.e < arr[i].s)
            s.push(arr[i]);

        else if (top.e < arr[i].e)
        {
            top.e = arr[i].e;
            s.pop();
            s.push(top);
        }
    }    
	}
    ld sm = 0;
    while (!s.empty())
    {
        Interval t = s.top();
        sm += t.e-t.s;
        s.pop();
    }
    cout<<sm/(2*PI);
}