#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
//#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 1123456
#define INF LLONG_MAX;
#define MOD 1000000


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin>>s;

	for(int i=0;i<s.size();i++){
		int a=(s[i]-'0');
		if(a%8==0){
			cout<<"YES\n"<<a<<endl;
			return 0;
		}
	}

	for(int i=0;i<s.size();i++){
		for(int j=i+1;j<s.size();j++){
			int a=10*(s[i]-'0')+s[j]-'0';
			if(a%8==0){
				cout<<"YES\n"<<a<<endl;
				return 0;
			}
		}
	}

	for(int i=0;i<s.size();i++){
		for(int j=i+1;j<s.size();j++){
			for(int k=j+1;k<s.size();k++){
				int a=100*(s[i]-'0')+10*(s[j]-'0')+s[k]-'0';
				if(a%8==0){
					cout<<"YES\n"<<a<<endl;
					return 0;
				}
			}
		}
	}
	cout<<"NO\n";

	return 0;
}