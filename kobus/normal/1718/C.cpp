#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>
#define INF INT_MAX

multiset<int> usefs;

vector<int> primos;
vector<vector<int>> coisas;

void fato(int n){
	int val=2;
	while(val*val<=n){
		if(n%val==0){
			primos.pb(val);
			while(n%val==0)n=n/val;
		}
		val++;
	}
	if(n!=1)primos.pb(n);
}


int32_t main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int t;
	cin>>t;
	while(t--){

		int n,q;
		cin>>n>>q;
		vector<int> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		fato(n);
		int pn=primos.size();
		coisas.resize(pn);
		for(int i=0;i<pn;i++){
			//n/primos[i] caras de primos[i] elementos cada
			//step de tamanho n/primos[i]
			int step=n/primos[i];
			coisas[i].resize(step);
			for(int j=0;j<step;j++){
				for(int k=j;k<n;k+=step){
					coisas[i][j]+=a[k];
				}
				usefs.insert(coisas[i][j]*step);
			}
		}

		cout<<(*usefs.rbegin())<<"\n";

		for(int i=0;i<q;i++){
			int p,x;
			cin>>p>>x;
			p--;

			for(int j=0;j<pn;j++){
				int step=n/primos[j];
				int rep=p%(step);
				usefs.erase(usefs.find(coisas[j][rep]*step));
				coisas[j][rep]-=a[p];
				coisas[j][rep]+=x;
				usefs.insert(coisas[j][rep]*step);
			}
			a[p]=x;
			cout<<(*usefs.rbegin())<<"\n";
		}

		
		usefs.clear();
		primos.clear();
		coisas.clear();

	}


}