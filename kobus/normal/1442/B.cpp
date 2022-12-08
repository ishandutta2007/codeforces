#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define MAXN 312345
#define MOD 998244353
#define f first
#define s second
#define pii pair<long long, long long>
#define INF INT_MAX
#define int long long

int pinv[212345];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		set<int> caras;
		set<int> carasrev;
		set<int> aparece;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			x--;
			pinv[x]=i;
			caras.insert(i);
			carasrev.insert(-i);
		}
		int resp=1;
		vector<int> coisa;
		for(int i=0;i<k;i++){
			int x;
			cin>>x;
			x--;
			x=pinv[x];
			coisa.pb(x);
			aparece.insert(x);
		}
		for(auto x:coisa){
			//cout<<x<<endl;
			int rem0=-1;
			int rem1=-1;
			auto prox=caras.upper_bound(x);
			if(prox!=caras.end() && aparece.find(*prox)==aparece.end()){
				rem0=*prox;
			}
			prox=carasrev.upper_bound(-x);
			if(prox!=carasrev.end() && aparece.find(-1*(*prox))==aparece.end()){
				rem1=-1*(*prox);
			}
			//cout<<rem0<<" "<<rem1<<endl;
			if(rem0==-1 && rem1==-1){
				resp*=0;
			}
			if(rem0!=-1 && rem1!=-1){
				resp=(2*resp)%MOD;
				caras.erase(rem0);
				carasrev.erase(-rem0);
			}
			if(rem0!=-1 && rem1==-1){
				caras.erase(rem0);
				carasrev.erase(-rem0);
			}
			if(rem0==-1 && rem1!=-1){
				caras.erase(rem1);
				carasrev.erase(-rem1);
			}
			aparece.erase(x);

		}
		cout<<resp<<endl;

	}


	return 0;
}