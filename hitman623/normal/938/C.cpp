#include <bits/stdc++.h>

#define int          long long
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
	int x,f=0;
	cin>>x;
	if(x==0) {cout<<"1 1\n";return;}
	int d=sqrt(2*x);
	rep(i,1,d+1){
		int h=i*i-x;
		if(h<=0) continue;
		int hh=sqrt(h);
		if(!hh) continue;
		if(hh*hh!=h || i/hh==0) continue;
		if(i/(i/hh)==hh){
    	    f=1;
			cout<<i<<" "<<i/hh<<endl;
	    	return;
		}
	}
	if(!f) cout<<-1<<endl;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
		solve();
	return 0;
}