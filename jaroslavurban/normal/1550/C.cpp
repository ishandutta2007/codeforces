#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

bool good(vector<int>a){
	int n=a.size();
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
			for(int k=j+1;k<n;++k){
				if((a[i]<=a[k]&&a[i]<=a[j]&&a[j]<=a[k])||
					 (a[i]>=a[k]&&a[i]>=a[j]&&a[j]>=a[k]))return false;
			}
	return true;
}

void ProGamerMove(){
	int n,res=0;cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<n;++i){
		vector<int>cur;
		for(int j=i;j<min(n,i+4);++j){
			cur.push_back(a[j]);
			if(good(cur))++res;
		}
	}
	cout<<res<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}