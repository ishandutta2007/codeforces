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

int n,m;
int fix(vector<int> v,int k){
	vector<int> seriatop(v.size());
	for(int i=0;i<v.size();i++){
		v[i]-=k;
		if(v[i]%m!=0){
			continue;
		}
		v[i]=v[i]/m;
		if(v[i]>=n)continue;
		seriatop[(((i-v[i]+n)%n)+n)%n]++;
	}
	//cout<<"seriatops"<<endl;
	//for(auto x:seriatop)cout<<x<<" ";
	//cout<<endl;
	int val=MAXN;
	for(int i=0;i<v.size();i++){
		val=min(val,n-seriatop[i]+i);
	}
	return val;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	vector<vector<int>> v(m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int val;
			cin>>val;
			v[j].pb(val-1);
		}
	}
	int moves=0;
	for(int i=0;i<m;i++){
		moves+=fix(v[i],i);
		//cout<<i<<" "<<moves<<endl;
	}
	cout<<moves<<endl;
}