#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define MAXN 312345
#define f first
#define s second
#define pii pair<long long, long long>
#define INF INT_MAX
#define int long long

int v[31234];
int aux[31234];


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++)cin>>v[i];
		bool ruim=0;
		int last=INF;
		int left=0;
		for(int i=0;i<n;i++){
			aux[i]=min(last,v[i]-left);
			if(aux[i]<0)ruim=1;
			left=max(left,v[i]-aux[i]);
			last=aux[i];
		}
		for(int i=0;i<n;i++){
			v[i]-=aux[i];
		}
		last=INF;
		for(int i=n-1;i>=0;i--){
			aux[i]=min(last,v[i]);
			last=aux[i];
		}
		for(int i=0;i<n;i++){
			v[i]-=aux[i];
		}
		for(int i=0;i<n;i++)if(v[i]!=0)ruim=1;
		if(ruim)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;

	}


	return 0;
}