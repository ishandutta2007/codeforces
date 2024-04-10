#include <bits/stdc++.h>
using namespace std; 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,k,cnt=0;
	cin>>n>>k;
	int score[n+5];
	for(int i=0;i<n;i++)cin>>score[i];
	for(int i=0;i<n;i++)if(score[i]>=score[k-1]&&score[i]>0)cnt++;
	cout<<cnt<<endl;
	return 0;
}