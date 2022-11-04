#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// use merge(all(vec1), all(vec2), vec3.begin()) to merge 2 vectors, use vec3.resize(vec1.size() + vec2.size()) first
// ll pos = partition_point(all(vec), pred) - vec.begin(); bool pred(ll a){return a<3};
// print number in binary -> cout << bitset<20>(n);

int n,total_ribs;
const int N=100010;
int cnt[N],freq[N],u[N]; // cnt of 10, freq of u=10;
int main(){
	cin>>n;
	for(int i=0;i<n;++i)cin>>u[i];
	int bst=1;
	set<int>active;
	for(int i=0;i<n;++i){
		if(freq[u[i]])--cnt[freq[u[i]]];
		if(!cnt[freq[u[i]]])active.erase(freq[u[i]]);
		++freq[u[i]];
		active.insert(freq[u[i]]);
		++cnt[freq[u[i]]];
		if(active.size()>2)continue;
		if(active.size()==1&&(*active.begin()==1||cnt[*active.begin()]==1))bst=i+1;
		if(active.size()==2){
			int u=*active.begin();
			auto xd=active.begin();advance(xd,1);
			int v=*xd;
			if(u==1&&v==2&&(cnt[u]==1||cnt[v]==1))bst=i+1;
			if(u==1&&cnt[u]==1)bst=i+1;
			if(u==v-1&&cnt[v]==1)bst=i+1;
		}
	}
	cout<<bst<<endl;
}