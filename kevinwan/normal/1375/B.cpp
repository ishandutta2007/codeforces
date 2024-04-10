#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=300+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=998244353;
#define mid ((l+r)>>1)
int a[mn][mn];
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
    	int n,m;
    	cin>>n>>m;
    	bool die=0;
    	for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j];
    	for(int i=0;i<n;i++)for(int j=0;j<m;j++){
    		int e=4;
    		if(!i||i==n-1)e--;
    		if(!j||j==m-1)e--;
    		if(e<a[i][j])die=1;
    		else a[i][j]=e;
    	}
    	if(die){printf("NO\n");continue;}
    	printf("YES\n");
    	for(int i=0;i<n;i++){
    		for(int j=0;j<m;j++)printf("%d ",a[i][j]);
    		printf("\n");
    	}
	}
}