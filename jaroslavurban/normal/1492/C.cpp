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
int n,m;
string s,t;
int pref[N],suf[N];

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	cin>>n>>m>>s>>t;
	int i=0;
	for(int j=0;j<m;++j){
		while(t[j]!=s[i])++i;
		pref[j]=i++;
	}
	i=n-1;
	for(int j=m-1;j>=0;--j){
		while(t[j]!=s[i])--i;
		suf[j]=i--;
	}
	int res=0;
	for(int j=0;j<m-1;++j)res=max(res,suf[j+1]-pref[j]);
	cout<<res<<endl;
}