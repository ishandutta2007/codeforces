#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// use merge(all(vec1), all(vec2), vec3.begin()) to merge 2 vectors, use vec3.resize(vec1.size() + vec2.size()) first
// ll pos = partition_point(all(vec), pred) - vec.begin(); bool pred(ll a){return a<3};
// print number in binary -> cout << bitset<20>(n);

const int N=2020;
int n,m;
string f[N];
string mf[N];
int main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		vector<pair<int,int>>r[2];
		cin>>n>>m;
		for(int i=0;i<n;++i)cin>>f[i];
		for(int i=0;i<n;++i)mf[i]=string(m,'.');
		int mx=-1;
		pair<int,int>posi;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				if(f[i][j]-'a'>mx&&f[i][j]!='.'){
					mx=f[i][j]-'a';
					posi={i,j};
				}
		for(int c=0;c<=mx;++c){
			vector<pair<int,int>>o;
			for(int i=0;i<n;++i)
				for(int j=0;j<m;++j)
					if(f[i][j]=='a'+c)o.push_back({i,j});
			if(o.empty()){
				r[0].push_back(posi);
				r[1].push_back(posi);
				continue;
			}
			sort(o.begin(),o.end());
			bool w=true,h=true;
			for(int i=1;i<o.size();++i){
				if(o[i-1].first!=o[i].first)h=false;
				if(o[i-1].second!=o[i].second)w=false;
			}
			if(!w&&!h)break;
			r[0].push_back({o.begin()->first,o.begin()->second});
			r[1].push_back({o.rbegin()->first,o.rbegin()->second});
			if(h)for(int i=o.begin()->second;i<=o.rbegin()->second;++i)mf[o.begin()->first][i]=c+'a';
			if(w)for(int i=o.begin()->first;i<=o.rbegin()->first;++i)mf[i][o.begin()->second]=c+'a';
		}
//		cerr<<mx<<endl;
//		for(int i=0;i<n;++i)
//			cerr<<mf[i]<<endl;
		bool pos=true;
		for(int i=0;i<n&&pos;++i)
			for(int j=0;j<m&&pos;++j)
				if(f[i][j]!=mf[i][j])
					pos=false;
		if(!pos){cout<<"NO\n";continue;}
		cout<<"YES\n"<<r[0].size()<<endl;
		for(int i=0;i<r[0].size();++i)cout<<r[0][i].first+1<<" "<<r[0][i].second+1<<" "<<
			r[1][i].first+1<<" "<<r[1][i].second+1<<endl;
	}
}