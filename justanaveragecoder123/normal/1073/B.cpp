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

int main() {
	IO;
	int n;
	cin>>n;
	vector<int> a(n), b(n);
	for(int i=0;i<n;++i) cin>>a[i];
	for(int i=0;i<n;++i) cin>>b[i];
	map<int, int> inv;
	for(int i=0;i<n;++i) inv[a[i]]=i;
	int akt=-1;
	for(int i=0;i<n;++i) {
		int uj=max(akt, inv[b[i]]);
		cout<<uj-akt<<" ";
		akt=uj;
	}cout<<"\n";
	return 0;
}