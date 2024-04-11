#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 312345;
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>
#define pb push_back
#define MOD 1000000007


int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int a,b,c,n;
		cin>>a>>b>>c>>n;
		int val=a+b+c+n;
		if(val%3!=0)cout<<"NO"<<endl;
		else{
			val=val/3;
			if(val>=a && val>=b && val>=c)cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}

}