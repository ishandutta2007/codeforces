#include <bits/stdc++.h>
using namespace std; 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	int colour[n+5];
	for(int i=0;i<n;i++)cin>>colour[i];
	if(colour[0]!=colour[n-1]){
		cout<<n-1<<endl;
		return 0;
	}
	int now=0;
	while(colour[now]==colour[n-1]&&colour[0]==colour[n-now-1])now++;
	cout<<max(n-1-now,1)<<endl;
	return 0;
}