#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int N=100100;
ll a[N];
int n;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	sort(a,a+n);
	bool w=true;
	if(n==1){
		w=a[0]%2; // 0 == second won
	}
	else if(a[0]==a[1]&&a[0]==0){
		w=0;
	}
	else{
		int cntsame=0;
		bool done=false;
		for(int i=0;i<n-1;++i)
			if(a[i]==a[i+1]){
				++cntsame;
				if((i&&a[i-1]==a[i]-1))done=true;
				--a[i];
			}
		if(cntsame>1||done){
			cout<<"cslnb\n";
			return 0;
		}
		ll res=cntsame;
		for(int i=0;i<n;++i)res+=a[i]-i;
		if(res%2)w=1;
		else w=0;
	}
	if(w)cout<<"sjfnb\n";
	else cout<<"cslnb\n";
}