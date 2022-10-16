#include <bits/stdc++.h>
using namespace std; 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,h;
	cin>>n>>h;
	int bottle[n+5];
	for(int i=1;i<=n;i++)cin>>bottle[i];
	int now=1;
	while(1){
		if(now==n+1){
			cout<<n<<endl;
			return 0;
		}
		int arr[now];
		for(int i=0;i<now;i++){
			arr[i]=bottle[i+1];
		}
		sort(arr,arr+now);
		int sum=0,place=0;
		if(now%2!=0){
			sum+=arr[0];
			place++;
		}
		while(place<now){
			place++;
			sum+=arr[place];
			place++;
		}
		if(sum>h){
			cout<<now-1<<endl;
			return 0;
		}
		now++;
	}
	return 0;
}