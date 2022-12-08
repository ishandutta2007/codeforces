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

int vn[3];
int v[112345];

int mincom[112345];
int minfim[112345];
int maxcom[112345];
int maxfim[112345];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	for(int i=0;i<3;i++)cin>>vn[i];

	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	mincom[0]=v[0];
	maxcom[0]=v[0];

	for(int i=1;i<n;i++){
		mincom[i]=min(mincom[i-1],v[i]);
		maxcom[i]=max(maxcom[i-1],v[i]);
	}

	minfim[n-1]=v[n-1];
	maxfim[n-1]=v[n-1];

	for(int i=n-2;i>=0;i--){
		minfim[i]=min(minfim[i+1],v[i]);
		maxfim[i]=max(maxfim[i+1],v[i]);
	}

	//for(int i=0;i<n;i++){
	//	cout<<mincom[i]<<" "<<maxcom[i]<<" ";
	//	cout<<minfim[i]<<" "<<maxfim[i]<<endl;
	//}

	int resp=-1*INF;
	for(int i=0;i<n;i++){
		int respar=0;
		respar+=v[i]*vn[1];
		if(vn[0]>=0)respar+=vn[0]*maxcom[i];
		else respar+=vn[0]*mincom[i];
		if(vn[2]>=0)respar+=vn[2]*maxfim[i];
		else respar+=vn[2]*minfim[i];
		//cout<<i<<" "<<respar<<endl;
		resp=max(resp,respar);
	}
	
	cout<<resp<<endl;

	return 0;
}