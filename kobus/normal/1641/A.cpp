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
		int n,x;
		cin>>n>>x;
		multiset<int> ms;
		for(int i=0;i<n;i++){
			int k;
			cin>>k;
			ms.insert(k);
		}
		int resp=0;
		while(ms.size()>0){
			int at=*ms.begin();
			ms.erase(ms.find(at));
			if(ms.find(at*x)!=ms.end()){
				ms.erase(ms.find(at*x));
			}
			else resp++;
		}
		cout<<resp<<endl;
	}

}