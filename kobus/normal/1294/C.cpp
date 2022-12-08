#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 312345;
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>
#define pb push_back
#define MOD 1000000007

pii dabom(int x,int k){
	//cout<<x<<" "<<k<<endl;
	for(int i=k;i*i<x;i++){
		if(x%i==0)return mp(i,x/i);
	}
	//cout<<"Ruim"<<endl;
	return mp(-1,-1);
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int qb=0;
		for(int i=2;i*i*i<=n;i++){
			if(n%i!=0)continue;
			//cout<<i<<endl;
			pii sla=dabom(n/i,i+1);
			if(sla.f!=-1){
				cout<<"YES"<<endl;
				cout<<i<<" "<<sla.f<<" "<<sla.s<<endl;
				qb=1;
				break;
			}
		}
		if(qb==0)cout<<"NO"<<endl;
	}

}