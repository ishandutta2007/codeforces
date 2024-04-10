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

int n,k;
const int K=256,N=100100;
int id[K];
int sz[K];
int a[N];
bool done[K];
int getid(int i){return id[i]==i?i:id[i]=getid(id[i]);}
int getsz(int i){return id[i]==i?sz[i]:getsz(getid(i));}
void uni(int i,int j){
	assert(!done[j]);
	id[j]=i;
	++sz[i];
	done[i]=done[j]=true;
}
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>k;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<K;++i)id[i]=i;
	for(int i=0;i<K;++i)sz[i]=1;
	for(int i=0;i<n;++i)
		if(!done[a[i]]){
			int l=a[i];
			while(l&&!done[l-1]&&a[i]-l+1<k)--l;
			bool getprev=l&&done[l-1]&&getsz(l-1)+a[i]-l+1<=k;
			for(int j=l+!getprev;j<=a[i];++j)
				uni(getid(l-getprev),j);
		}
	for(int i=0;i<n;++i)cout<<getid(a[i])<<" ";cout<<endl;
}