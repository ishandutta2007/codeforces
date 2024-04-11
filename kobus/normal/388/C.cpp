#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAXN 5123
#define INF INT_MAX
#define MOD 1000000007
#define pii pair<int,int>
#define double long double 
#define int long long

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	int c=0,j=0;
	vector<int> resto;

	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		//cout<<x<<endl;
		for(int k=0;k<x;k++){
			int y;
			cin>>y;
			if(k<x/2)c+=y;
			else if(x-k-1<x/2)j+=y;
			else resto.pb(y);
			//cout<<y<<" "<<c<<" "<<j<<endl;
		}
	}

	sort(resto.begin(),resto.end());
	for(int i=0;i<resto.size();i++){
		//cout<<resto[i]<<endl;
		if((resto.size()-i)%2==1)c+=resto[i];
		else j+=resto[i];
	}
	cout<<c<<" "<<j<<endl;



	return 0;
}