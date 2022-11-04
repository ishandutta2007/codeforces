#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		string s;cin>>s;
		vector<pair<int,int>>pts;
		int n=s.size();
		int x=0,y=0;
		for(int i=0;i<n;++i){
			if(s[i]=='L')--x;
			if(s[i]=='R')++x;
			if(s[i]=='U')++y;
			if(s[i]=='D')--y;
			pts.push_back({x,y});
		}
		bool done=false;
		for(int i=0;i<pts.size();++i){
			x=0,y=0;
			for(int j=0;j<n;++j){
				int nx=x,ny=y;
				if(s[j]=='L')--nx;
				if(s[j]=='R')++nx;
				if(s[j]=='U')++ny;
				if(s[j]=='D')--ny;
				if(nx==pts[i].first&&ny==pts[i].second)continue;
				x=nx;y=ny;
			}
			if(!x&&!y){
				cout<<pts[i].first<<" "<<pts[i].second<<endl;
				done=true;
				break;
			}
		}
		if(!done)cout<<"0 0\n";
	}
}