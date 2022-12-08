#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define MAXN 512345
#define INF INT_MAX/2
#define MOD 1000000007

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(11);
  	cout.setf(ios::fixed);

	int n;
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		if(s.size()>10){
			char fc=s[0];
			char lc=s[s.size()-1];
			cout<<fc<<s.size()-2<<lc<<endl;
		}
		else cout<<s<<endl;
	}

	return 0;
}