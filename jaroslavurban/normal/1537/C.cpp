#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	int n;cin>>n;
	vector<int>h(n);
	for(int i=0;i<n;++i)cin>>h[i];
	sort(h.begin(),h.end());
	pair<int,int>mn={INT_MAX,0};
	for(int i=0;i+1<n;++i)mn=min(mn,{h[i+1]-h[i],i});
	if(n==2){
		cout<<h[0]<<" "<<h[1]<<endl;
		return;
	}
	for(int i=mn.second+1;i<n;++i)cout<<h[i]<<" ";
	for(int i=0;i<=mn.second;++i)cout<<h[i]<<" ";
	cout<<endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}