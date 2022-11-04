#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100100;
int n;
int a[N];
bool done[N];
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		cin>>n;
		for(int i=0;i<n;++i)done[i]=false;
		for(int i=0;i<n;++i)cin>>a[i];
		ll res=0;
		for(int i=30;i>=0;--i){
			int cnt=0;
			for(int j=0;j<n;++j)if(!done[j]&&((1<<i)&a[j])){
				done[j]=true;++cnt;
			}
			res+=(ll)cnt*(cnt-1)/2;
		}
		cout<<res<<endl;
	}
}