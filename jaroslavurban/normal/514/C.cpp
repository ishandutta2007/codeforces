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

int n,m;
const int mod=1e9+7,N=300010;
int hashes[N];
set<string>sorted[N];
string strings[N];
int ohashes[N];
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>strings[i];
		for(int j=0;j<strings[i].size();++j)hashes[i]=(hashes[i]+(strings[i][j]-'a')*(j+1))%mod;
		ohashes[i]=hashes[i];
	}
	sort(hashes,hashes+n);
	int nn=unique(hashes,hashes+n)-hashes;
	for(int i=0;i<n;++i){
		int idx=lower_bound(hashes,hashes+nn,ohashes[i])-hashes;
		assert(hashes[idx]==ohashes[i]);
		assert(idx<nn);
		sorted[idx].insert(strings[i]);
	}
	n=nn;
	for(int i=0;i<m;++i){
		string s;cin>>s;
		string tmps=s;
		int hash=0;
		for(int j=0;j<s.size();++j)hash=(hash+(s[j]-'a')*(j+1))%mod;
		bool pos=false;
		for(int j=0;!pos&&j<s.size();++j){
			for(int k=0;!pos&&k<3;++k)
				if(s[j]-'a'!=k){
					tmps[j]=k+'a';
					int tmphash=(hash+mod+(k-s[j]+'a')*(j+1))%mod;
					int idx=lower_bound(hashes,hashes+n,tmphash)-hashes;
					assert(idx>=nn||sorted[idx].size());
					if(idx<nn&&hashes[idx]==tmphash)
						if(sorted[idx].count(tmps))
							pos=true;
				}
			tmps[j]=s[j];
		}
		if(pos)cout<<"YES\n";
		else cout<<"NO\n";
	}
}