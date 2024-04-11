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
		vector<int> v;
		set<int> s;
		int n;
		cin>>n;
		int mini=0;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			v.pb(x);
			s.insert(x);
		}
		//cout<<"LEU"<<endl;
		set<int> ss;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int val=abs(v[i]-v[j]);
				if(s.find(val)==s.end())ss.insert(val);
			}
		}
		while(ss.size()>0 && s.size()<=305){
			int val=*ss.begin();
			ss.erase(val);
			if(s.find(val)!=s.end())continue;
			for(auto x:v){
				if(s.find(abs(val-x))==s.end())ss.insert(abs(val-x));
			}
			s.insert(val);
			v.pb(val);
		}
		if(s.size()>300)cout<<"NO"<<endl;
		else{
			cout<<"YES"<<endl;
			cout<<v.size()<<endl;
			for(auto x:v)cout<<x<<" ";
			cout<<endl;
		}

	}
}