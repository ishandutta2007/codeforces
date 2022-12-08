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
#define INF INT_MAX
#define MOD 1000000


int v[1123456];
int help[1123456];
int sum[1123456];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin>>n;

	for(int i=0;i<n;i++)cin>>v[i];
	for(int i=1;i<n;i++){
		help[max(i-v[i],0ll)]++;
		help[i]--;
	}
	sum[0]=help[0];
	for(int i=1;i<n;i++){
		sum[i]=sum[i-1]+help[i];
	}
	int resp=0;
	for(int i=0;i<n;i++){
		if(sum[i]==0)resp++;
	}
	cout<<resp<<endl;
	

	return 0;
}