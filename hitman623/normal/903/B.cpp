#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)		cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii 		vector<pii>
#define mi 			map<int,int>
#define mii			map<int,pii>	
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;

void solve()
{
	int h1,a1,c1,h2,a2;
	cin>>h1>>a1>>c1>>h2>>a2;
	int strikes=(h2+a1-1)/a1;
	// h1+h*c1-(h+strikes-1)*a2>0
	// h1+(c1-a2)h-()
	int heals=((strikes-1)*a2-h1+c1-a2)/(c1-a2);
	if(heals<0) heals=0;
	cout<<heals+strikes<<endl;
	rep(i,0,heals)
		cout<<"HEAL\n";
	rep(i,0,strikes)
		cout<<"STRIKE\n";	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
	return 0;
}