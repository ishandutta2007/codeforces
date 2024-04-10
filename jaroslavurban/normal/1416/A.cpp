#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=300100;
int a[N];
int previdx[N];
int maxdist[N];
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n;
		for(int i=0;i<n;++i)cin>>a[i];
		for(int i=0;i<=n;++i)previdx[i]=-1;
		for(int i=0;i<=n;++i)maxdist[i]=-1;
		for(int i=0;i<n;++i){
			maxdist[a[i]]=max(maxdist[a[i]],i-previdx[a[i]]);
			previdx[a[i]]=i;
		}
		for(int i=0;i<=n;++i)maxdist[i]=max(maxdist[i],n-previdx[i]);
		int idx=0;
		vector<int>res(n);
		for(int i=n;i>=1;--i){
			while(idx<=n&&maxdist[idx]>i)++idx;
			if(idx>n)res[i-1]=-1;
			else res[i-1]=idx;
		}
		for(int i=0;i<n;++i)cout<<res[i]<<" ";cout<<endl;
	}	
}