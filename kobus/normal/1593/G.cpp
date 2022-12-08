#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define INF INT_MAX/2
#define int long long
#define mp make_pair
#define f first
#define s second


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		vector<int> sla(s.size()+1);
		for(int i=0;i<s.size();i++){
			if(s[i]=='['||s[i]==']'){
				if(i%2)sla[i+1]=1;
				else sla[i+1]=-1;
			}
			sla[i+1]+=sla[i];
		}
		int q;
		cin>>q;
		while(q--){
			int a,b;
			cin>>a>>b;
			cout<<abs(sla[b]-sla[a-1])<<endl;
		}
	}
}