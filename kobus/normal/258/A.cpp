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
#define INF INT_MAX;
#define MOD 1000000

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin>>s;
	bool deld=false;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(!((i==n-1&&deld==false)||(deld==false&&s[i]=='0'))){
			cout<<s[i];
		}
		else deld=true;
	}
	cout<<endl;
}