#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define INF INT_MAX/2
#define int long long
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>
#define C 1000000000
#define val 1000000

int dg[112345];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n,s;
	cin>>n>>s;
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		dg[a]++;dg[b]++;
	}
	if(n==2){
		cout<<setprecision(11)<<fixed;
		cout<<(long double)s<<endl;
		return 0;
	}
	int l=0;
	for(int i=0;i<n;i++){
		if(dg[i]==1)l++;
	}
	cout<<setprecision(11)<<fixed;
	cout<<(((long double)s)/l)*2.<<endl;

}