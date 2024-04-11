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


int v1[112345];
int v2[112345];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>v1[i];
	}
	for(int i=0;i<n;i++){
		cin>>v2[i];
	}
	int total=0;
	for(int i=0;i<n;i++){
		total+=v1[i];
	}
	sort(v2,v2+n);
	int cap=v2[n-1]+v2[n-2];
	if(cap>=total){
		cout<<"YES"<<endl;
	}
	else cout<<"NO"<<endl;
	

	return 0;
}