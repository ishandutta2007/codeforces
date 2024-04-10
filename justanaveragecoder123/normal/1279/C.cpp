#include<bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin>>T;
	while(T--) {
		int n,m;
		cin>>n>>m;
		stack<int> a;
		vector<int> aa(n);
		for(int i=0;i<n;++i) {
			cin>>aa[i];
		}
		for(int i=n-1;i>=0;--i) {
			a.push(aa[i]);
		}
		
		vector<int> b(m);
		for(int j=0;j<m;++j) cin>>b[j];
		
		set<int> ok;
		long long ans=0;
		for(int j=0;j<m;++j) {
			if(ok.find(b[j])!=ok.end()) {
				ans++;
				ok.erase(b[j]);
			}else {
				while(!a.empty() && a.top()!=b[j]) {
					ok.insert(a.top());
					a.pop();
				}
				
				ans+=2*(ok.size())+1;
				a.pop();
			}
		}
		
		cout<<ans<<"\n";
	}
	return 0;
}