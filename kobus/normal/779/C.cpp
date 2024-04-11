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
#define INF LLONG_MAX;
#define MOD 1000000

int v[212345];

int v1[212345];
int v2[212345];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>v1[i];
	for(int i=0;i<n;i++)cin>>v2[i];
	int resp=0;
	for(int i=0;i<n;i++){
		resp+=v2[i];
		v[i]=v1[i]-v2[i];
	}
	sort(v,v+n);
	for(int i=0;i<k||v[i]<0;i++)resp+=v[i];
	cout<<resp<<endl;

	return 0;
}