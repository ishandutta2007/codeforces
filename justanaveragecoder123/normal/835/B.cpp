#include<bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int k;
	string n;
	cin>>k>>n;
	int sum=0;
	for(auto i:n) sum+=i-'0';
	
	sort(n.begin(),n.end());
	
	int ans=0;
	for(auto& i:n) {
		if(sum>=k) break;
		while(i<'9') {i++;sum++;}
		ans++;
	}
	
	cout<<ans<<"\n";
	return 0;
}