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

set<string> s;

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		int mark=s.size();
		string st;
		cin>>st;
		s.insert(st);
		if(mark==s.size()){
			cout<<"YES\n";
		}
		else cout<<"NO\n";
	}
	
	
	return 0;
}