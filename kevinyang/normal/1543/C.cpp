#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		map<pair<int,int>,double>dp;
		set<pair<int,int>>s;
		queue<pair<int,int>>q;
		int base = (int)1e9;
		int v;
		if(true){
			int c,m,p;
			double cc,mm,pp,vv;
			cin >> cc >> mm >> pp >> vv;
			c = cc*(int)1e7; m = mm*(int)1e7; p = pp*(int)1e7; v = vv*(int)1e7;
			//cout << c << " " << m << " " << p << " " << v << "\n";
			dp[{c*base+m,p*base}] = 1.0;
			s.insert({c*base+m,p*base});
			q.push({c*base+m,p*base});
		}
		while(!q.empty()){
			pair<int,int>cur = q.front(); q.pop();
			int c = cur.first/base;
			int m = cur.first%base;
			int p = cur.second/base;
			int dist = cur.second%base;
			if(c==0&&m==0)continue;
			if(m==0){
				double prob = (double)c/(c+p);
				int rem = min(c,v);
				int nc = c-rem; int nm = m; int np = p+rem;
				dp[{nc*base+nm,np*base+dist+1}]+=dp[{c*base+m,p*base+dist}]*prob;
				if(s.find({nc*base+nm,np*base+dist+1})==s.end())q.push({nc*base+nm,np*base+dist+1});
				s.insert({nc*base+nm,np*base+dist+1});
			}
			else if(c==0){
				double prob = (double)m/(m+p);
				int rem = min(m,v);
				int nc = c; int nm = m-rem; int np = p+rem;
				dp[{nc*base+nm,np*base+dist+1}]+=dp[{c*base+m,p*base+dist}]*prob;
				if(s.find({nc*base+nm,np*base+dist+1})==s.end())q.push({nc*base+nm,np*base+dist+1});
				s.insert({nc*base+nm,np*base+dist+1});
			}
			else{
				if(true){
					double prob = (double)c/(c+m+p);
					int rem = min(c,v);
					int nc = c-rem; int nm = m+rem/2; int np = p+rem/2;
					dp[{nc*base+nm,np*base+dist+1}]+=dp[{c*base+m,p*base+dist}]*prob;
					if(s.find({nc*base+nm,np*base+dist+1})==s.end())q.push({nc*base+nm,np*base+dist+1});
					s.insert({nc*base+nm,np*base+dist+1});
				}
				if(true){
					double prob = (double)m/(c+m+p);
					int rem = min(m,v);
					int nc = c+rem/2; int nm = m-rem; int np = p+rem/2;
					//cout << dp[{c*base+m,p*base+dist}] << " " << prob << "\n";
					dp[{nc*base+nm,np*base+dist+1}]+=dp[{c*base+m,p*base+dist}]*prob;
					if(s.find({nc*base+nm,np*base+dist+1})==s.end())q.push({nc*base+nm,np*base+dist+1});
					s.insert({nc*base+nm,np*base+dist+1});
				}
			}
		}
		cout << fixed << setprecision(10);
		double ans = 0;
		for(pair<int,int>cur: s){
			int c = cur.first/base;
			int m = cur.first%base;
			int p = cur.second/base;
			int dist = cur.second%base;
			//cout << dp[{c*base+m,p*base}] << " " << p << " " << c+m+p << " " << dist+1 << "\n";
			ans+=((double)dp[{c*base+m,p*base+dist}]*(double)p/((double)c+m+p))*(dist+1);
		}
		cout << ans << "\n";
	}
	return 0;
}