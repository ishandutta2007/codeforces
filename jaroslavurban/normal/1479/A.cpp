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

const int N=100100,inf=1e9;
int n;
int a[N];

int ask(int idx){
	if(a[idx]!=-inf)return a[idx];
	cout<<"? "<<idx<<endl;
	cin>>a[idx];
	return a[idx];
}


main(){
	cin.tie(0);ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i)a[i]=-inf;
	a[0]=a[n+1]=inf;
	if(ask(1)<ask(2)){
		cout<<"! 1\n";
		return 0;
	}
	if(ask(n-1)>ask(n)){
		cout<<"! "<<n<<endl;
		return 0;
	}
	int l=2,r=n-1;
	while(l<r){
		int m=(l+r)/2;
		if(ask(m)<ask(m+1))r=m;
		else l=m+1;
	}
	cout<<"! "<<l<<endl;
}