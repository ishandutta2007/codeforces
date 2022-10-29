#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int s[60],h,mod;
void solve(){
	int q;
	cin>>q;
	while(q--){
		int t,x,k;
		cin>>t;
		if(t==1){
			cin>>x>>k;
			int r=x;
			h=-1;
			while(r) h++,r/=2;
			mod=1LL<<h;
			k%=mod;
			if(k<0) k+=mod;
			s[h]+=k;
			s[h]%=mod;
		}
		else if(t==2){
			cin>>x>>k;
			int r=x;
			h=-1;
			while(r) h++,r/=2;
			mod=1LL<<h;
			k%=mod;
			if(k<0) k+=mod;
			rep(i,h,60){
				s[i]+=k;
				s[i]%=mod;
				mod=(mod*2);
				k=(k*2)%mod;
			}
		}
		else{
			cin>>x;
			h=-1;
			int r=x;
			while(r) h++,r/=2;
			mod=1LL<<h;
			cout<<x<<" ";
			x=(1LL<<h)+(x-(1LL<<h)+s[h])%mod;
			while(x/2){
				x/=2;
				h--;
				mod/=2;
				int y=(1LL<<h)+(x-(1LL<<h)+mod-s[h])%mod;
				cout<<y<<" ";
			}
			cout<<endl;
		}
	}    
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}