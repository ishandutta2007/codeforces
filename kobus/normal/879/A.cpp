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
#define int long long

pii v[112345];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin>>n;

	int time=0;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		if(a>=time){
			time=a;
		}
		else{
			time-=a;
			time=ceil((1.*time)/b);
			time*=b;
			time+=a;
		}
		time++;
	}
	cout<<time-1<<endl;

	return 0;
}