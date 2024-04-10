#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=200100;
int n;
string words[N];

int tr(char c){
	vector<int>diffs(n);
	for(int i=0;i<n;++i)diffs[i]=2*count(words[i].begin(),words[i].end(),c)-words[i].size();
	sort(diffs.begin(),diffs.end());
	int diff=0;
	while(diffs.size()&&diff+diffs.back()>0)diff+=diffs.back(),diffs.pop_back();
	return n-diffs.size();
}

void ProGamerMove(){
	cin>>n;
	for(int i=0;i<n;++i)cin>>words[i];
	int res=0;
	for(int c='a';c<='e';++c)res=max(res,tr(c));
	cout<<res<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}