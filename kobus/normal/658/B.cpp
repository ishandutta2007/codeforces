#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 512345
#define INF INT_MAX/2
#define MOD 1000000007
#define int long long

int f[152345];


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,k,q;
	cin>>n>>k>>q;

	for(int i=1;i<=n;i++)cin>>f[i];
	set<pii> s;
	//amizade depois numero
	while(q--){
		int id,cara;
		cin>>id>>cara;
		if(id==1){
			if(s.size()<k)s.insert(mp(f[cara],cara));
			else{
				pii p=*s.begin();
				if(p.f<f[cara]){
					s.erase(*s.begin());
					s.insert(mp(f[cara],cara));
				}
			}
		}
		else{
			if(s.find(mp(f[cara],cara))==s.end()){
				cout<<"NO"<<endl;
			}
			else{
				cout<<"YES"<<endl;
			}
		}
	}
	


	return 0;
}