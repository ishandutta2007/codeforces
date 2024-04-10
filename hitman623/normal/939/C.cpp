#include <bits/stdc++.h>

#define int         long long
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
int n,s,f,t[200005],cur=0,mx=0,ans;
void solve(){
	cin>>n;
	rep(i,0,n){
		cin>>t[i];
		t[i+n]=t[i];
	}
	cin>>s>>f;
	int l=f-s;
	rep(i,0,l){
		cur+=t[i];
	}
	mx=cur;
	ans=s;
	rep(i,l,n+l){
		cur+=t[i];
		cur-=t[i-l];
		if(cur>mx){
			mx=cur;
			ans=(s-i+l-1);
			while(ans<=0) ans+=n;
		}
		else if(cur==mx){
			int tempans=(s-i+l-1);
			while(tempans<=0){
				tempans+=n;
			}
			ans=min(ans,tempans);			
		}
	}
	if(ans>n) ans-=n;
	cout<<ans;
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