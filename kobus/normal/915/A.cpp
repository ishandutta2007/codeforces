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
#define MAXN 3123
#define INF LLONG_MAX
#define MOD 1000000007

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int b,l;
	int resp=INF;
	cin>>b>>l;

	for(int i=0;i<b;i++){
		int c;
		cin>>c;
		if(l%c==0)resp=min(resp,l/c);

	}

	cout<<resp<<endl;
	

  	return 0;

}