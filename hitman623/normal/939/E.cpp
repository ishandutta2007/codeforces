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
int q,p[500005],a[500005],mx=0,cur=0;
double z=0;
double cal(int x){
	return mx-1.0l*(p[x]+mx)/(x+2);
}
void solve(){
	cin>>q;
	rep(i,0,q){
		int t;
		cin>>t;
		if(t==1){
			int x;
			cin>>x;
			mx=x;
			a[cur]=x;
			p[cur]=(cur?p[cur-1]:0)+x;
			cur++;
		}
		else{
			if(cur==1){
				cout<<z<<endl;
			}
			else{
				int lo=0,hi=cur;
				while(hi-lo>2){
					int mid1=lo+(hi-lo)/3;
					int mid2=hi-(hi-lo)/3;
					if(cal(mid1)<cal(mid2)){
						lo=mid1;
					}
					else hi=mid2;
				}
				double ans=cal(lo);
				if(lo+1<cur){
					ans=max(ans,cal(lo+1));
				}
				if(lo+2<cur){
					ans=max(ans,cal(lo+2));
				}
				cout<<ans<<endl;
			}
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cout<<fixed<<setprecision(10);
//	cin>>t;
	while(t--)
		solve();
	return 0;
}