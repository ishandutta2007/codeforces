#include<bits/stdc++.h>
using namespace std;

int n,x,y;

int ask(vector<int> p) {
	cout<<"? ";
	cout<<p.size()<<" ";
	for(auto i:p) cout<<i<<" ";
	cout<<"\n";cout.flush();fflush(stdout);
	int ans;
	cin>>ans;
	return ans; 
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>x>>y;
	vector<vector<int>> groups(10);
	for(int i=1;i<=n;++i) {
		for(int j=0;j<10;++j) {
			if(i&(1<<j)) groups[j].push_back(i);
		}
	}
	
	vector<int> diff;
	for(int i=0;i<10;++i) {
		if(groups[i].size()) {
			
			int ans=ask(groups[i]);
			if(ans==y || ans==(x^y)) {
				//cerr<<"diff found\n";
				diff.push_back(i);
			}
		}
	}
	
	/*cerr<<"DIFF: ";
	for(auto i:diff) cerr<<i<<" ";
	cerr<<"\n";*/
	
	
	int len=groups[diff[0]].size();
	int L=0, R=len-1;
	while(L<R) {
		int mid=(L+R)/2;
		vector<int> akt;
		for(int i=L;i<=mid;++i) {
			akt.push_back(groups[diff[0]][i]);
		}
		int ans=ask(akt);
		if(ans==y || ans==(x^y)) {
			R=mid;
		}else {
			L=mid+1;
		}
	}
	
	int egyik=groups[diff[0]][L];
	int masik=egyik;
	for(int i=0;i<(int)diff.size();++i) {
		masik^=(1<<diff[i]);
	}
	
	if(egyik>masik) swap(egyik, masik);
	cout<<"! "<<egyik<<" "<<masik<<"\n";
	cout.flush();fflush(stdout);
	return 0;
}