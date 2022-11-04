#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=5050;
int s[N];
int fn1[N];
int n,idx;

int getfn1(int i){
	if(i>=n)return n;
	if(s[i]!=1)return i;
	return fn1[i]=getfn1(fn1[i]);
}

int jump(){
	while(idx<n&&s[idx]==1)++idx;
	if(idx==n)return 0;
	if(idx+s[idx]>n){
		int res=(s[idx]+idx)-n;
		s[idx]=n-idx;
		return res;
	}
	for(int i=idx;i<n;){
		int oi=i;
		i+=s[i];
		i=getfn1(i);
		s[oi]=max(1,s[oi]-1);
	}
	return 1;
}

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		idx=0;
		cin>>n;
		iota(fn1,fn1+n,1);
		for(int i=0;i<n;++i)cin>>s[i];
		ll res=0;
		int r=0;
		while(r=jump()){
			res+=r;
//			for(int i=0;i<n;++i)cout<<s[i]<<" ";cout<<endl;
		}
		cout<<res<<endl;
	}
}