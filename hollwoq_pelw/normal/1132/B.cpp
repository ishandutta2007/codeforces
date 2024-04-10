#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ll n,i,j,k,a;
	vector< ll > v;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;
		v.push_back(a);
	}

	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	
	ll sum=0;
	
	for(i=0;i<n;i++){
		sum += v[i]; 
	}
	ll que;
	cin>>que;
	while(que--){
		cin>>a;
		cout<<sum-v[a-1]<<"\n";
	}
	return 0;
}