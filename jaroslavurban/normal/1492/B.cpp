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
int p[N],pmx[N];
int n;

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		cin>>n;
		for(int i=0;i<n;++i)cin>>p[i];
		pmx[0]=0;
		for(int i=1;i<=n;++i)pmx[i]=max(pmx[i-1],p[i-1]);
		vector<int>res;
		int ptr=n;
		while(ptr>0){
			vector<int>pb;
			pb.push_back(p[ptr-1]);
			while(ptr-1>0&&pmx[ptr]==pmx[ptr-1])pb.push_back(p[--ptr-1]);
			reverse(pb.begin(),pb.end());
			res.insert(res.end(),pb.begin(),pb.end());
			--ptr;
		}
		for(auto r:res)cout<<r<<" ";cout<<endl;
	}
}