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
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
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
		int n,k;
		cin>>n>>k;
		ll sc=0;
		int v=k/n,nnv=k%n;
		memset(a,0,sizeof(a));
		for(int i=0,k=0;i<n;i++){
			for(int j=0;j<v+(i<nnv);j++,k++){
				if(k==n)k=0;
				a[i][k]=1;
			}
		}
		if(nnv)printf("2\n");
		else printf("0\n");
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)printf("%d",a[i][j]);
			printf("\n");
		}
	}
}