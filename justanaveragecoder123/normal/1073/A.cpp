#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define xx first
#define yy second
#define sz(x) (int)(x).size()
#define gc getchar
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;

int cnt[1001][26];
int main() {
	IO;
	int n;
	cin>>n;
	string t;
	cin>>t;
	
	for(int i=0;i<sz(t);++i) {
		cnt[i][t[i]-'a']++;
	}
	
	for(int i=0;i<26;++i) {
		for(int j=1;j<sz(t);++j) {
			cnt[j][i]+=cnt[j-1][i];
		}
	}
	
	for(int i=0;i<sz(t);++i) {
		for(int j=i;j<sz(t);++j) {
			int n=j-i+1;
			bool ok=true;
			for(int k=0;k<26;++k) {
				int akt=cnt[j][k]-(i>0?cnt[i-1][k]:0);
				ok&=akt<=n/2;
			}
			if(ok) {
				cout<<"YES\n";
				for(int k=i;k<=j;++k) {
					cout<<t[k];
				}cout<<"\n";
				return 0;
			}
		}
	}

	cout<<"NO\n";
	
	
	return 0;
}