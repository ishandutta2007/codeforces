#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=300100;
int n,q;
int a[N];
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		cin>>n>>q;
		ll res=0;
		for(int i=0;i<n;++i)cin>>a[i];
		for(int i=0;i<n;++i)if((!i||a[i-1]<a[i])&&(i+1==n||a[i]>a[i+1]))res+=a[i];
		else if(i&&i+1!=n&&a[i-1]>a[i]&&a[i]<a[i+1])res-=a[i];
		cout<<res<<endl;
	}
}