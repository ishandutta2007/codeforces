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

map<string,int> m;

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin>>n;

	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		if(m[s]==0){
			cout<<"OK"<<endl;
		}
		else{
			cout<<s<<m[s]<<endl;
		}
		m[s]++;
	}

	return 0;
}