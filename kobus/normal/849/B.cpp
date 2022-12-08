#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
 
#define MAXN 11234567890123
#define INF INT_MAX/2
#define MOD 1000000

long long v[1123];

int v1[3]={3,2,1};
int v2[3]={1,1,2};
int v3[3]={2,3,3};

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	bool resp=0;

	for(int i=1;i<=n;i++)cin>>v[i];

	for(int i=0;i<3;i++){
		bool respar=1;
		ll a=v2[i],b=v1[i];
		double inc=1.*(v[v3[i]]-v[v2[i]])/(v3[i]-v2[i]);
		for(int j=1;j<=n;j++){
			//cout<<i<<" "<<(v[a]+(j-a)*inc)<<" "<<(v[b]+(j-b)*inc)<<endl;
			//cout<<v[a]<<" "<<j-a<<" "<<inc<<endl;
			if(!((v[a]+(j-a)*inc)-v[j]==0 ^ (v[b]+(j-b)*inc)-v[j]==0))respar=0;
		}
		resp|=respar;
	}

	bool respar=1;
	ll a=1;
	ll b=-1;
	ll inc=v[2]-v[1];
	//cout<<inc<<endl;
	for(int i=1;i<=n;i++){
		//cout<<b<<endl;
		if(v[i]==v[1]+(i-1)*inc){
			//cout<<"entra\n";
			int y=0;
		}
		else if(b==-1){
			//cout<<"entra2\n";
			b=i;
		}
		else if(v[i]!=v[b]+(i-b)*inc)respar=0;

	}
	resp|=(respar&&b!=-1);






	if(resp)cout<<"Yes\n";
	else cout<<"No\n";




	return 0;
}