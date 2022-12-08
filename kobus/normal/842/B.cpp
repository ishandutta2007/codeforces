#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
 
#define MAXN 11234567890123
#define INF INT_MAX/2
#define MOD 1000000



int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int rp,b;
	cin>>rp>>b;
	int rn=rp-b;
	int s;
	cin>>s;
	int resp=0;
	for(int i=0;i<s;i++){
		int x,y,r;
		cin>>x>>y>>r;
		if(x*x+y*y>=(rn+r)*(rn+r)){
			if(x*x+y*y<=(rp-r)*(rp-r)){
				resp++;
			}
		}
	}
	cout<<resp<<endl;
	return 0;
}