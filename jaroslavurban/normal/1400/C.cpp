#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'

// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// print number in binary -> cout << bitset<20>(n);

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		string s;cin>>s;
		int x;cin>>x;
		int n=s.size();
		vector<int>res(n,-1);
		bool pos=true;
		for(int i=0;i<x;++i)
			if(i+x<n)res[i+x]=s[i]-'0';
			else if(s[i]=='1')pos=false;
		for(int i=n-1;i+x>=n;--i)
			if(i-x>=0){
				if(~res[i-x]&&res[i-x]!=s[i]-'0')pos=false;
				else res[i-x]=s[i]-'0';
			}
			else if(s[i]=='1')pos=false;
		for(int i=x;i<n-x;++i)
			if(s[i]=='0'){
				if(res[i-x]==1||res[i+x]==1)pos=false;
				else res[i-x]=res[i+x]=0;
			}
		for(int i=x;i<n-x;++i)
			if(s[i]=='1'&&res[i-x]==0&&res[i+x]==0)pos=false;
		if(!pos){cout<<-1<<endl;continue;}
		for(int i=0;i<n;++i)
			if(res[i]==-1)cout<<1;
			else cout<<res[i];
		cout<<endl;
	}
}