#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std; 
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	map<char,int>cnt;
	for(char c='a';c<='z';c++)cnt[c]=0;
	char t;
	string lol;
	for(int i=0;i<n;i++){
		cin>>t;
		getline(cin,lol);
		cnt[t]++;
	}
	int ans=0;
	for(char c='a';c<='z';c++){
		int x=cnt[c]/2;
		ans+=(x-1)*(x)/2;
		x+=cnt[c]%2;
		ans+=(x-1)*(x)/2;
	}
	cout<<ans<<endl;
	return 0;
}