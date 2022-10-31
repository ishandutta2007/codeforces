#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef __int128 big;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
const int N = 1e5+7;
int A[N];
void F(int l,int r,vector<pair<int,int> > &ans){
	if ((A[l]+A[r])%2==0){
		A[l] = A[r];
	}
	else{
		A[r] = A[l];
	}
	ans.push_back({l,r});
}
void solve() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i+=1){
		cin>>A[i];
	}
	if (n==1){
		cout<<"0\n";
		return;
	}
	vector<pair<int,int> > ans;
	F(1,n,ans);	
	for(int i = 2;i<n;i+=1){
		if ((A[1]+A[i])%2==0){
			F(i,n,ans);
		}
		else{
			F(1,i,ans);
		}
	}
	cout<<ans.size()<<endl;
	for(auto [x,y]:ans){
		cout<<x<<' '<<y<<endl;
	}
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
	    solve();
    }
}