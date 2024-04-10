#include <bits/stdc++.h>
#define	int 		long long
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
int v[2002];
void solve(){
	int p,k,cur=0;
	cin>>p>>k;
	while(p){
		v[cur++]=(p%k);
		p/=k;
	}
	rep(i,0,2000){
		if(i%2 && v[i]){
			v[i]=k-v[i];
			int h=1;
			rep(j,i+1,2000){
				if(!h) break;
				if(v[j]+h>=k) v[j]=(v[j]+h)%k;
				else v[j]+=h,h=0;
			}
		}
	}
	rep(i,0,2001){
		if(v[i]) cur=i;
	}
	cout<<cur+1<<endl;
	rep(i,0,cur+1){
		cout<<v[i]<<" ";
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