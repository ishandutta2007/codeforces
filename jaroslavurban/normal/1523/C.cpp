#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	int n;cin>>n;
	vector<int>lnum;
	vector<vector<int>>hist;
	for(int i=0;i<n;++i){
		int a;cin>>a;
		if(a==1){
			lnum.push_back(1);
			hist.push_back({});
			if(hist.size()>1){
				hist.back()=hist[lnum.size()-2];
				hist.back().push_back(lnum[lnum.size()-2]);
			}
			for(auto h:hist.back())cout<<h<<".";
			cout<<"1\n";
		}else{
			while(lnum.size()){
				if(lnum.back()==a-1){
					for(auto h:hist.back())cout<<h<<".";
					cout<<(++lnum.back())<<"\n";
					break;
				}
				lnum.pop_back();
				hist.pop_back();
			}
		}
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}