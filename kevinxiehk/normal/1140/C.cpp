#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,k;
	cin>>n>>k;
	pair<long long,long long>song[n+5];
	for(long long i=0;i<n;i++){
		cin>>song[i].second>>song[i].first;
	}
	sort(song,song+n);
	priority_queue<long long>len;
	len.push(song[n-1].second*-1);
	long long tt,sum,ans=0,nowlen=0;
	nowlen+=song[n-1].second;
	
	for(long long i=1;i<=n;i++){
		if(song[n-i].second>(len.top()*-1)||i<=k){
			if(i!=1){
				len.push(song[n-i].second*-1);
				nowlen+=song[n-i].second;
				if(i>k){
					nowlen+=len.top();
					len.pop();
				}
			}
		}
		else continue;
		long long tans=nowlen*(song[n-i].first);
		//cout<<nowlen<<" "<<song[n-i].first<<" "<<i<<" "<<(len.top()*-1)<<endl;
		ans=max(ans,tans);
	}
	cout<<ans<<endl;
	return 0;
}