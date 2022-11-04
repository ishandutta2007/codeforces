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

int ask(int l,int r){
	cout<<"? "<<l+1<<" "<<r+1<<endl;
	int res;cin>>res;return res-1;
}

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int n;cin>>n;
	int secidx=ask(0,n-1);
	int l,r;
	if(secidx&&ask(0,secidx)==secidx){
		l=0,r=secidx-1;
	}else{
		l=secidx+1;r=n-1;
	}
	while(l<r){
		int m=(l+r)/2;
		if(secidx<m){
			if(ask(secidx,m)==secidx)r=m-1;
			else l=m+1;
		}
		else{
			if(ask(m+1,secidx)==secidx)l=m+1;
			else r=m;
		}
	}
	cout<<"! "<<l+1<<endl;
}