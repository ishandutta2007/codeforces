#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 212345
#define INF INT_MAX/2
#define MOD 1000000

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	int d=0,e=0;

	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		if(a>0)d++;
		else e++;
	}

	if(d>1 && e>1){
		cout<<"No"<<endl;
	}
	else cout<<"Yes"<<endl;

	return 0;
}