#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;



void ProGamerMove(){
	int n,m,k;cin>>n>>m>>k;
	vector<string>f(n,string(m,'.'));
	auto take=[&](int i,int j){
		set<char>banned;
		for(int dy=-2;dy<=+2;++dy)
			for(int dx=-2;dx<=+2;++dx){
				int ni=i+dy;
				int nj=j+dx;
				if(ni<n&&ni>=0&&nj<m&&nj>=0)banned.insert(f[ni][nj]);
			}
		for(int c='a';c<='z';++c)if(!banned.count(c))return c;
		assert(0);
		return 0;
	};
	if(!(n&1)){
		if((k&1)||m/2*n<k){cout<<"NO\n";return;}
		for(int j=0;k&&j+1<m;j+=2)
			for(int i=0;k&&i<n;++i){
				f[i][j]=f[i][j+1]=take(i,j);
				--k;
			}
		for(int i=0;i+1<n;++i)
			for(int j=0;j<m;++j)
				if(f[i][j]=='.')
					f[i][j]=f[i+1][j]=take(i,j);
	}else{
		if(k<m/2||(k-m/2)&1){cout<<"NO\n";return;}
		for(int j=0;j+1<m;j+=2,--k)f[0][j]=f[0][j+1]=take(0,j);
		for(int j=0;k&&j+1<m;j+=2)
			for(int i=0;k&&i<n;++i)if(f[i][j]=='.'){
				f[i][j]=f[i][j+1]=take(i,j);
				--k;
			}
		for(int i=0;i+1<n;++i)
			for(int j=0;j<m;++j)
				if(f[i][j]=='.')
					f[i][j]=f[i+1][j]=take(i,j);
	}
	cout<<"YES\n";
	for(int i=0;i<n;++i)cout<<f[i]<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}