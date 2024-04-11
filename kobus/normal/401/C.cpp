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
#define INF INT_MAX;
#define MOD 1000000

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,m;
	cin>>n>>m;
	if(n-1>m||m>2*(n+1)){
		cout<<"-1\n";
		return 0;
	}
	if(n==m){
		for(int i=0;i<n;i++)cout<<"10";
		cout<<endl;
		return 0;
	}
	if(n-1==m){
		cout<<"0";
		for(int i=0;i<m;i++)cout<<"10";
		cout<<endl;
		return 0;
	}

	while(m>0){
		if(m>(n+1)){
			cout<<"11";
			m-=2;
		}
		else{
			cout<<"1";
			m--;
		}
		if(n>0){
			cout<<"0";
			n--;
		}
	}
	cout<<endl;

	return 0;
}