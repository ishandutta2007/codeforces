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
int n,q,k;
int a[N];

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	cin>>n>>q>>k;
	for(int i=0;i<n;++i)cin>>a[i];
	vector<int>pref(n);
	for(int i=0;i<n;++i)pref[i]=(i?pref[i-1]:0)+((i==n-1?k+1:a[i+1])-(i?a[i-1]:0)-2);
	while(q--){
		int l,r;cin>>l>>r;--l;--r;
		if(l==r){
			cout<<k-1<<endl;
		}else{
			cout<<pref[r-1]-pref[l]+(k-a[r-1]-1)+(a[l+1]-2)<<endl;
		}
	}
}