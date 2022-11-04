#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'

// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// print number in binary -> cout << bitset<20>(n);

const int N=1000010,inf=1e9;
int dp[N][8];
bool f[3][N];
int n,m;
int diff(int idx,int i){
	int d=0;
	for(int j=0;j<min(n,m);++j)
		d+=(f[j][idx])!=!!(i&(1<<j));
	return d;
}
int solvedp(int idx,int num){
	if(~dp[idx][num])return dp[idx][num];
	if(idx==max(n,m))return 0;
	dp[idx][num]=inf;
	for(int i=0;i<8;++i){
		bool pos=true;
		if(idx)
			for(int j=0;j<min(n,m)-1;++j){
				int cnt1=!!(num&(1<<j))+!!(num&(1<<(j+1)))+!!(i&(1<<j))+!!(i&(1<<(j+1)));
//				cerr<<num<<" "<<i<<" "<<cnt1<<endl;
				if(cnt1%2==0)pos=false;
			}

		if(pos){
			int future=solvedp(idx+1,i);
//			cerr<<idx<<" "<<future<<endl;
			int df=diff(idx,i);
			if(future!=inf)dp[idx][num]=min(dp[idx][num],future+df);
		}
	}
	return dp[idx][num];
}
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>m;
	if(n>=4&&m>=4){cout<<-1<<endl;return 0;}
	if(n<2||m<2){cout<<0<<endl;return 0;}
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j){
			char c;cin>>c;
			if(n<=m)f[i][j]=c-'0';
			else f[j][i]=c-'0';
		}
//	for(int i=0;i<min(n,m);++i,cerr<<endl)
//		for(int j=0;j<max(n,m);++j)
//			cerr<<f[i][j]<<" ";
	int res=solvedp(0,0);
	if(res==inf)cout<<-1<<endl;
	else cout<<res<<endl;
}