#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=101100,M=1010;
int n,r;
int x[N],y[N],t[N],v[N],mx[N];
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>r>>n;++n;
	x[0]=y[0]=1;
	for(int i=1;i<n;++i)cin>>t[i]>>x[i]>>y[i];
	for(int i=n-1;i>=0;--i){
		int j=i+1;
		for(;j<n&&t[j]-M<t[i];++j)
			if(abs(x[j]-x[i])+abs(y[j]-y[i])<=t[j]-t[i])v[i]=max(v[i],v[j]+1);
		if(j<n)v[i]=max(v[i],mx[j]+1);
		mx[i]=max(mx[i+1],v[i]);
	}
//	for(int i=0;i<n;++i)cout<<v[i]<<" ";cerr<<endl;
	cout<<v[0]<<endl;
}