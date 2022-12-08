#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define INF INT_MAX/2
#define int long long
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>
#define C 1000000000

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		//cout<<":)"<<endl;
		int n;
		cin>>n;
		vector<int> v(n);
		map<int,int> m;
		//cout<<"AAAA"<<n<<endl;
		for(int i=0;i<n;i++){
			cin>>v[i];
			m[v[i]]++;
		}
		bool ruim=0;
		for(auto x:m)if((x.s%2)==1)ruim=1;
		if(ruim){
			cout<<-1<<endl;
			continue;
		}
		//cout<<"AA"<<endl;
		int com=0;
		vector<pii> ops;
		vector<int> seg;
		for(int i=0;i<n;i+=2){
			for(int j=1;j<n;j++){
				if(v[i+j]==v[i]){
					vector<int> h(j-1);
					for(int k=1;k<j;k++){
						h[k-1]=v[i+k];
						ops.pb(mp(v[i+k],com+j+k));
					}
					reverse(h.begin(),h.end());
					for(int k=2;k<=j;k++)v[i+k]=h[k-2];
					seg.pb(j);
					com+=2*j;
					//cout<<"com "<<com<<endl;
					break;
				}
			}
		}
		cout<<ops.size()<<"\n";
		for(auto x:ops)cout<<x.s<<" "<<x.f<<"\n";
		cout<<seg.size()<<"\n";
		for(auto x:seg)cout<<2*x<<" ";
		cout<<"\n"<<endl;
	}

}