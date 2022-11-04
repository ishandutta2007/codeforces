#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N=200100,M=60,L='1',P=15,MAGIC=40;
string likes[N];
bool done[N];
int n,m,p;

pair<int,string>tr(int idx){
	int mp[M],pm[P];
	int cnt=0;
	for(int i=0;i<m;++i){
		if(likes[idx][i]==L)pm[cnt]=i,mp[i]=cnt++;
		else mp[i]=-1;
	}
//	cerr<<idx<<endl;
	vector<int>common(1<<cnt);
	for(int i=0;i<n;++i){
		int com=0;
		for(int j=0;j<m;++j)if(~mp[j]&&likes[i][j]==L)com|=1<<mp[j];
		++common[com];
//		cerr<<com<<" "<<common[com]<<endl;
	}
	vector<int>cando(1<<cnt);
	for(int m=0;m<1<<cnt;++m)
		for(int s=m;s;s=(s-1)&m)
			cando[s]+=common[m];
	pair<int,string>res={0,string(m,'0')};
	for(int msk=0;msk<1<<cnt;++msk)
		if(cando[msk]>=(n+1)/2){
			string rs(m,'0');
			for(int j=0;j<cnt;++j)if(msk&(1<<j))rs[pm[j]]='1';
//			cerr<<rs<<endl;
			res=max(res,{__builtin_popcount(msk),rs});
		}
	return res;
}

void ProGamerMove(){
	cin>>n>>m>>p;
	for(int i=0;i<n;++i)cin>>likes[i];
	pair<int,string>res={0,string(m,'0')};
	for(int i=0;i<min(n,MAGIC);++i){
		int idx=rng()%n;
		if(done[idx])continue;
		done[idx]=true;
		res=max(res,tr(idx));
	}
//	int lks=0;
//	for(int i=0;i<n;++i){
//		bool l=true;
//		for(int j=0;j<m;++j)if(res.second[j]==L&&likes[i][j]!=L)l=false;
//		lks+=l;
//	}
//	assert(lks>=(n+1)/2);
	cout<<res.second<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
//	cin>>tc;
	while(tc--)ProGamerMove();
}