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

const int N=200100;
int a[N];
int n,k;

int tr(int m){
	vector<int>na(n);
	for(int i=0;i<n;++i)na[i]=2*(a[i]>=m)-1;
	vector<int>mxp(n),mxs(n);
	for(int i=n-2;i>=0;--i)mxs[i]=max(0,mxs[i+1]+na[i+1]);
	for(int i=1;i<n;++i)mxp[i]=max(0,mxp[i-1]+na[i-1]);
	int sm=0;
	for(int i=0;i<k-1;++i)sm+=na[i];
	int mx=0;
	int l=0;
	for(int r=k-1;r<n;++r){
		sm+=na[r];
		mx=max(mx,sm+mxp[l]+mxs[r]);
		sm-=na[l++];
	}
	return mx;
}

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=0;i<n;++i)cin>>a[i];
	int l=1,r=n+1;
	while(l<r){
		int m=(l+r)/2;
		if(tr(m)>0)l=m+1;
		else r=m;
	}
	cout<<l-1<<endl;
}