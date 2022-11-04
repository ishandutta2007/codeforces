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

const int N=110;
int h[N];
int n,k;

int th(int idx){
	if(idx==n-1)return idx+1;
	if(h[idx]>=h[idx+1])return th(idx+1);
	++h[idx];
	return idx+1;
}

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		cin>>n>>k;
		for(int i=0;i<n;++i)cin>>h[i];
		int pos=0;
		for(int i=0;i<k;++i){
			pos=th(0);
			if(pos==n)break;
		}
		if(pos==n)cout<<-1<<endl;
		else cout<<pos<<endl;
	}
}