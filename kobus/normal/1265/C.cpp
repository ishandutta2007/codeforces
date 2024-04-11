#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAXN 1123
#define INF LLONG_MAX
#define MOD 32416187567
#define pii pair<int,int> 
#define int long long

int aux[1123456];
int v[1123456];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
			aux[i]=0;
		}
		aux[0]++;
		int curr=0;
		for(int i=1;i<n;i++){
			if(v[i]!=v[i-1])curr++;
			aux[curr]++;
		}
		curr++;
		pair<pii,int> resp=mp(mp(0,0),0);
		int gold=0;
		int silver=aux[0];
		int bronze=aux[1];
		int p1=0;
		int p2=1;
		int p3=2;
		for(int i=0;i<curr;i++){
			p1++;
			gold+=aux[i];
			silver-=aux[i];
			while(silver<=gold && p2<curr){
				silver+=aux[p2];
				bronze-=aux[p2];
				p2++;
			}
			while(bronze<=gold && p3<curr){
				bronze+=aux[p3];
				p3++;
			}
			while(p3<curr && gold+silver+bronze+aux[p3]<=n/2){
				bronze+=aux[p3];
				p3++;
			}
			if(p1!=p2 && p2!=p3 && gold+silver+bronze<=n/2)
				resp=mp(mp(gold,silver),bronze);
			//cout<<p1<<" "<<p2<<" "<<p3<<" "<<gold<<" "<<silver<<" "<<bronze<<endl;
		}
		cout<<resp.f.f<<" "<<resp.f.s<<" "<<resp.s<<endl;
	}

	return 0;
}