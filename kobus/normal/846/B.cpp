#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
//#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 11234567890123
#define INF INT_MAX/2
#define MOD 1000000

int v[112];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,k,t;
	cin>>n>>k>>t;
	int tot=0;

	for(int i=0;i<k;i++){
		cin>>v[i];
		tot+=v[i];
	}

	sort(v,v+k);
	int resp=0;

	for(int i=0;i<=n;i++){

		int respar=(k+1)*i;
		int tpar=t-tot*i;

		if(tpar<0)continue;

		for(int j=0;j<k;j++){

			int num=min((tpar-(tpar%v[j]))/v[j],n-i);
			respar+=num; 
			tpar-=num*v[j];
			//cout<<j<<" "<<num<<" "<<tpar<<endl;

		}
		//cout<<respar<<endl;
		resp=max(respar,resp);

	}
	cout<<resp<<endl;

	
	return 0;
}