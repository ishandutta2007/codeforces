#include <bits/stdc++.h>
using namespace std; 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,t,cnt=0,tcnt;
	cin>>n;
	for(int i=0;i<n;i++){
		tcnt=0;
		for(int i=0;i<3;i++){
			cin>>t;
			tcnt+=t;
		}
		if(tcnt>=2)cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}