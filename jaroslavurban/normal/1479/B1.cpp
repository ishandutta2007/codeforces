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

const int N=100100;
vector<int>nxt[N];
int a[N];

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int n;cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=n-1;i>=0;--i)nxt[a[i]].push_back(i);
	vector<int>x={a[0]},y;
	for(int i=1;i<n;++i){
		if(y.empty()&&a[i]!=x.back()){
			x.push_back(a[i]);
			continue;
		}
		if(y.empty()){
			y.push_back(a[i]);
			continue;
		}
		while(nxt[x.back()].size()&&nxt[x.back()].back()<i)nxt[x.back()].pop_back();
		while(nxt[y.back()].size()&&nxt[y.back()].back()<i)nxt[y.back()].pop_back();
		if(x.back()==a[i]){
			y.push_back(a[i]);
			continue;
		}
		if(y.back()==a[i]){
			x.push_back(a[i]);
			continue;
		}
		if(nxt[x.back()].empty()){
			y.push_back(a[i]);
			continue;
		}
		if(nxt[y.back()].empty()){
			x.push_back(a[i]);
			continue;
		}
		if(nxt[x.back()].back()<nxt[y.back()].back()){
			x.push_back(a[i]);
			continue;
		}
		else{
			y.push_back(a[i]);
			continue;
		}
	}
	x.erase(unique(x.begin(),x.end()),x.end());
	y.erase(unique(y.begin(),y.end()),y.end());
	cout<<x.size()+y.size()<<endl;
}