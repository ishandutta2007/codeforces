#include<bits/stdc++.h>
using namespace std;
vector<int>ax,ay;
char c[101][101];
char d[101][101];
vector<char>s;
void solve(){
	int n,m,k;
	cin >> n >> m >> k;
	int sum=0;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			cin >> c[i][j];
			sum+=c[i][j]=='R';
		}
	}
	ax.clear();ay.clear();
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			if(i%2==1) ax.push_back(i),ay.push_back(j);
			else ax.push_back(i),ay.push_back(m-j+1);
		}
	}
	int cnt=0;
	int ptr=1;
	for(int i=0; i<n*m ;i++){
		d[ax[i]][ay[i]]=s[ptr];
		if(c[ax[i]][ay[i]]=='R') cnt++;
		if(ptr!=k && cnt==(sum/k)+(ptr<=sum%k)) ptr++,cnt=0;
		
	}
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			cout << d[i][j];
		}
		cout << '\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	s.push_back('?');
	for(int i=0; i<26 ;i++){
		s.push_back('A'+i);
		s.push_back('a'+i);
	}
	for(int i=0; i<10 ;i++){
		s.push_back('0'+i);
	}
	int t;cin >> t;while(t--) solve();
}