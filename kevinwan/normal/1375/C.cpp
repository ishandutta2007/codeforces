#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=3e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=998244353;
#define mid ((l+r)>>1)
int a[mn];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int tc;
    cin>>tc;
    while(tc--){
    	int n;
    	cin>>n;
    	for(int i=0;i<n;i++)cin>>a[i];
    	printf("%s\n",a[0]<a[n-1]?"YES":"NO");
	}
}