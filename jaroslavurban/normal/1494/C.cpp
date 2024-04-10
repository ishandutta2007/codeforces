#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=200100;
int a[N],b[N];
int n,m;

int solve(vector<int>a,vector<int>b){
	if(b.empty()||a.empty())return 0;
	vector<pair<int,int>>all;
	for(auto aa:a)all.push_back({aa,0});
	for(auto bb:b)all.push_back({bb,1});
	sort(all.begin(),all.end());
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int n=a.size(),m=b.size();
	vector<int>suf(m+1);
	int ca=n-1;
	for(int i=m-1;i>=0;--i){
		while(ca>=0&&a[ca]>b[i])--ca;
		if(ca>=0&&a[ca]==b[i])++suf[i];
		suf[i]+=suf[i+1];
	}
	int cb=0;
	int res=0;
	int lpos=0,bin=0,sz=0;
	for(int i=0;i<all.size();++i){
		if(all[i].second==0){
			++sz;continue;
		}
		++cb;++bin;
		if(!sz)continue;
		while(lpos<all.size()){
			if(all[lpos].second==0){
				++lpos;
				continue;
			}
			if(all[lpos].first<all[i].first-sz+1){
				--bin;
				++lpos;continue;
			}
			break;
		}
		res=max(res,bin+suf[cb]);
	}
	return res;
}


main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		cin>>n>>m;
		for(int i=0;i<n;++i)cin>>a[i];
		for(int i=0;i<m;++i)cin>>b[i];
		vector<int>a1,a2,b1,b2;
		for(int i=0;i<n;++i)if(a[i]<0)a1.push_back(-a[i]);
		else a2.push_back(a[i]);
		for(int i=0;i<m;++i)if(b[i]<0)b1.push_back(-b[i]);
		else b2.push_back(b[i]);
//		solve(a2,b2);
//		return 0;
		cout<<solve(a1,b1)+solve(a2,b2)<<endl;
	}
}