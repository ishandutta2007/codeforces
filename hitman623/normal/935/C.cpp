#include <bits/stdc++.h>

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
#define hell        1000000000
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;

void solve(){
	cout<<fixed<<setprecision(10);
	double R,x1,y1,x2,y2;
	cin>>R>>x1>>y1>>x2>>y2;
	if((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)<R*R){
		double d=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
		if(d==0){
			R-=1e-7;
			R/=2;
			cout<<x2+(1e-8)+R<<" "<<y2<<" "<<R<<endl;
			return;
		}
		cout<<(-(R-d)*x2+(R+d)*x1)/(2*d)<<" "<<(-(R-d)*y2+(R+d)*y1)/(2*d)<<" "<<(R+d)/2<<endl;
	}
	else{
		cout<<x1<<" "<<y1<<" "<<R<<endl;
	}
}

signed main()
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