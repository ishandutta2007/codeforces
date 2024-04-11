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
	
	vector<int> v;
	int i=0;
	while(v.size()<=1000){
		if(i%3==0 || i%10==3)i++;
		else{ v.pb(i);i++;}
	}
	int t;
	cin>>t;
	while(t--){
		int x;
		cin>>x;
		cout<<v[x-1]<<endl;
	}
	
}