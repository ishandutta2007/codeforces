#include<iostream>
#include<map>
using namespace std;
typedef long long ll;
int n,k,m;
map<string,int>mm;
int c[100001];
int a[100001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k >> m;
	for(int i=1; i<=n ;i++){
		string s;
		cin >> s;
		mm[s]=i;
	}
	for(int i=1; i<=n ;i++){
		cin >> c[i];
	}
	for(int i=1; i<=k ;i++){
		int q;
		cin >> q;
		int mini=1e9;
		for(int j=1; j<=q ;j++){
			cin >> a[j];
			mini=min(mini,c[a[j]]);
		}
		for(int j=1; j<=q ;j++){
			c[a[j]]=mini;
		}
	}
	ll ans=0;
	for(int i=1; i<=m ;i++){
		string s;
		cin >> s;
		ans+=c[mm[s]];
	}
	cout << ans << endl;
}