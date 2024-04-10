#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define pb push_back
#define ll long long
#define mod 998244353
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
int ans,T,a[N],i,j;
ll n;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		if(n%2050){cout<<"-1\n";continue;}
		n/=2050;ans=0;
		while(n){
			ans+=n%10;n/=10;
		}
		cout<<ans<<"\n";
	}
}