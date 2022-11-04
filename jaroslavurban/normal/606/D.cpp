#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100100;
int n,m;
int con[N];
int l[N],r[N];
vector<pair<int,int>>inc,ninc; // w,idx
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int w,in;cin>>w>>in;
		if(in)inc.push_back({w,i});
		else ninc.push_back({w,i});
	}
	sort(inc.begin(),inc.end());
	sort(ninc.begin(),ninc.end());
	for(int i=1;i<n;++i){
		con[i]=inc[i-1].first;
		l[inc[i-1].second]=i-1;
		r[inc[i-1].second]=i;
	}
	int last=0;
	for(int i=0;i<n&&last<ninc.size();++i){
		for(int j=i-2;j>=0&&last<ninc.size()&&con[i]<=ninc[last].first;--j,++last){
			l[ninc[last].second]=i;
			r[ninc[last].second]=j;
		}
	}
	if(last!=ninc.size()){cout<<-1<<endl;return 0;}
	for(int i=0;i<m;++i)cout<<l[i]+1<<" "<<r[i]+1<<endl;
}