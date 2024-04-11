#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1123;
#define mp make_pair
#define f first
#define s second

bool menor(int a,int b){
	if(a%2==0 && b%2==1)return 1;
	return 0;
}

int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		sort(v.begin(),v.end(),menor);
		int good=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(gcd(v[i],2*v[j])!=1)good++;
			}
		}
		cout<<good<<endl;

	}

}