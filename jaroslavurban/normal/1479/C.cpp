#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// bool xd=any_of(a.begin(),a.end(),[&](int x){return x==9;});
// all_of, none_of
// int cnt=count(a.begin(),a.end(),x);
// bool found=binary_search(a.begin(),a.end(),x); true if x in sorted array
// int xd=*max_element(a.begin(),a.end());
// min_element

typedef long long ll;
typedef long double ld;

int l,r;
int n=32;

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	cin>>l>>r;
	cout<<"YES\n32 ";
	int diff=r-l;
	vector<tuple<int,int,int>>res;
	res.push_back({1,n,l});
	if(diff>0){
		int mx=-1;
		for(int i=0;i<30;++i)if(diff&(1<<i))mx=i;
		for(int i=0;i<mx;++i)
			for(int j=i+1;j<mx;++j)
				res.push_back({i+2,j+2,(1<<i)});
		int sm=(1<<mx);
		for(int i=mx-1;i>=0;--i){
			if((1<<i)&diff){
				res.push_back({i+2,mx+3,sm});
				sm+=1<<i;
			}
		}
		res.push_back({mx+3,n,1});
		for(int i=0;i<=mx;++i)res.push_back({1,i+2,l});
		for(int i=0;i<=mx;++i)res.push_back({i+2,n,1<<i});
	}
	cout<<res.size()<<endl;
	for(auto r:res)cout<<get<0>(r)<<" "<<get<1>(r)<<" "<<get<2>(r)<<endl;
}