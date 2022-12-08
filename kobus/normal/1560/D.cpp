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

//a  o power of 2
int val(string a,string &b){
	int mf=0;
	for(int i=0;i<a.size();i++){
		int k=0;
		for(int j=0;j<b.size();j++){
			if(b[j]==a[k])k++;
		}
		mf=max(mf,k);
	}
	return b.size()-mf+a.size()-mf;
}


int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		string x;
		cin>>x;
		int num=1;
		int resp=50;
		while(num<LLONG_MAX/2){
			resp=min(resp,val(to_string(num),x));
			num*=2;
		}
		resp=min(resp,val(to_string(num),x));
		cout<<resp<<"\n";
	}
	
}