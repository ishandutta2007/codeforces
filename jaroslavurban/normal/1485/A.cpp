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

const int M=1010;
int cnt(int a,int b){
	int res=0;
	while(a){
		a/=b;++res;
	}
	return res;
}

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int a,b;cin>>a>>b;
		int res=1e9;
		for(int i=b==1;i<M;++i)res=min(res,i+cnt(a,b+i));
		cout<<res<<endl;
	}
}