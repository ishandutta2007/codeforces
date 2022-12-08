#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>
#define INF INT_MAX

int32_t main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> v(n);
		for(int i=0;i<n;i++)cin>>v[i];
		int time=0;
		int xorca=0;
		set<int> values={0};
		for(int i=0;i<n;i++){
			if(v[i]==0){
				values={xorca};
				continue;
			}
			bool good=0;
			if(values.find(v[i]^xorca)!=values.end()){
				values={xorca};
				continue;
			}
			if(good)continue;
			time++;
			xorca^=v[i];
			values.insert(xorca);

		}
		cout<<time<<endl;
	}


}