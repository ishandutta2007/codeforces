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
	
	vector<string> pals;
	for(char c='a';c<='z';c++){
		string s;
		s.pb(c);
		pals.pb(s);
	}
	for(char c='a';c<='z';c++){
		for(char d='a';d<='z';d++){
			string s;
			s.pb(c);
			s.pb(d);
			pals.pb(s);
		}
	}
	for(char c='a';c<='z';c++){
		for(char d='a';d<='z';d++){
			for(char e='a';e<='z';e++){
				string s;
				s.pb(c);
				s.pb(d);
				s.pb(e);
				pals.pb(s);
			}
		}
	}

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		for(auto x:pals){
			int tem=0;
			for(int i=0;i<s.size()-x.size()+1;i++){
				int fit=1;
				for(int j=0;j<x.size();j++){
					//cout<<"tt "<<x[j]<<" "<<s[i+j]<<endl;
					if(x[j]!=s[i+j])fit=0;
				}
				//cout<<x<<" "<<i<<" "<<fit<<endl;
				if(fit==1){
					tem=1;
					break;
				}
			}
			if(tem==0){
				cout<<x<<endl;
				break;
			}
		}
	}
}