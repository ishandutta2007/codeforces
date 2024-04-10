#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=200100;
ll n,w;
pair<int,int>a[N];

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		cin>>n>>w;
		for(int i=0;i<n;++i)cin>>a[i].first;
		for(int i=0;i<n;++i)a[i].second=i;
		sort(a,a+n);
		ll sm=0;
		int idx=n-1;
		while(idx>=0&&a[idx].first>w)--idx;
		if(idx==-1){cout<<-1<<endl;continue;}
		int oidx=idx;
		while(idx>=0&&2*sm<w){sm+=a[idx].first;--idx;}
		if(sm*2>=w){
			cout<<oidx-idx<<endl;
			for(int i=idx+1;i<=oidx;++i)cout<<a[i].second+1<<" ";cout<<endl;
		}else cout<<-1<<endl;
	}
}