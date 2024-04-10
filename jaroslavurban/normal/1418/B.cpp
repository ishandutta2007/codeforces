#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=110;
int a[N];

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n;
		for(int i=0;i<n;++i)cin>>a[i];
		vector<int>ul;
		for(int i=0;i<n;++i){int l;cin>>l;if(!l){ul.push_back(a[i]);a[i]=-1e9;}}
		sort(ul.rbegin(),ul.rend());
		for(int i=n-1;i>=0;--i)if(a[i]==-1e9){a[i]=ul.back();ul.pop_back();}
		for(int i=0;i<n;++i)cout<<a[i]<<" ";cout<<endl;
	}
}