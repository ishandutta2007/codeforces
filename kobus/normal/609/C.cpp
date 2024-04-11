#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 1123456
#define INF INT_MAX/2
#define MOD 1000000

int v[212345];
int v2[212345];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>v[i];
		sum+=v[i];
	}
	sort(v,v+n);
	for(int i=0;i<n;i++){
		v2[i]=sum/n;
	}
	sum=sum%n;
	for(int i=0;i<n;i++){
		v2[i]+=min(sum,1ll);
		sum-=min(sum,1ll);
	}
	sort(v2,v2+n);
	int resp=0;
	for(int i=0;i<n;i++){
		resp+=abs(v[i]-v2[i]);
	}
	resp=resp/2;
	cout<<resp<<endl;

	return 0;
}