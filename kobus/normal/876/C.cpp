#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 1123456
#define INF INT_MAX/2
#define MOD 1000000

int sum(int a){
	int resp=0;
	for(int i=0;i<=11;i++){
		resp+=a%10;
		a=a/10;
	}
	return resp;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	vector<int> resp;
	for(int i=n-1000;i<=n;i++){
		if(i>=0){
			if(i+sum(i)==n){
				resp.pb(i);
			}
		}
	}
	cout<<resp.size()<<endl;
	for(int i=0;i<resp.size();i++){
		cout<<resp[i]<<endl;
	}


	return 0;
}