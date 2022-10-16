#include <bits/stdc++.h>
using namespace std; 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int cnt[5],a,n,sum=0;
	cin>>n;
	for(int i=1;i<=4;i++)cnt[i]=0;
	for(int i=0;i<n;i++){
		cin>>a;
		cnt[a]++;
	}
	sum+=cnt[4];
	sum+=cnt[3];
	cnt[1]=max(0,cnt[1]-cnt[3]);
	cnt[2]+=cnt[1]/2;
	cnt[2]+=cnt[1]%2;
	sum+=cnt[2]/2;
	sum+=cnt[2]%2;
	cout<<sum<<endl;
	return 0;
}