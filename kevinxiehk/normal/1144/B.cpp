#include <bits/stdc++.h>
using namespace std; 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	priority_queue<int>a,b;
	int n,t,oddcnt=0,evencnt=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t;
		if(t%2==0){
			evencnt++;
			a.push(t*-1);
		}
		else{
			oddcnt++;
			b.push(t*-1);
		}
	}
	int ans=0;
	//cout<<oddcnt<<" "<<evencnt<<endl;
	if(evencnt>oddcnt){
		for(int i=1;i<(evencnt-oddcnt);i++){
			ans+=(a.top()*-1);
			a.pop();
		}
	}
	else if(oddcnt>evencnt){
		for(int i=1;i<(oddcnt-evencnt);i++){
			ans+=(b.top()*-1);
			b.pop();
		}
	}
	cout<<ans<<endl;
	return 0;
}