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


int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<pii> v;
		for(int i=0;i<n;i++){
			int a,b;
			cin>>a>>b;
			v.pb(mp(a,b));
		}
		sort(v.begin(),v.end());
		int bom=1;
		for(int i=1;i<n;i++){
			if(v[i].f<v[i-1].f || v[i].s<v[i-1].s){
				bom=0;
			}
		}
		if(bom==0){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		int x=0,y=0;
		for(int i=0;i<n;i++){
			while(x<v[i].f){
				cout<<"R";
				x++;
			}
			while(y<v[i].s){
				cout<<"U";
				y++;
			}
		}
		cout<<endl;
	}

}