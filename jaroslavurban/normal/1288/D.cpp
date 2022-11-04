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

const int inf=1e9+1,cm=256;
int bst[cm];
int bsti[cm];
int a[8];
int n,m,mm;
int mn(char xd){
	int mnn=inf;
	for(int i=0;i<m;++i)if(xd&(1<<i))mnn=min(a[i],mnn);
	return mnn;
}
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>m;
	if(n==1){
		cout<<"1 1\n";
		return 0;
	}
	bst[0]=inf;
	mm=(1<<m);
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j)cin>>a[j];
		for(int j=1;j<mm;++j){
			int c=mn(j);
			if(c>=bst[j]){
				bst[j]=c;
				bsti[j]=i;
			}
		}
	}
	int res=0;
	int ri;
	for(int i=1;i<mm;++i){
		int c=min(bst[i],bst[mm-i-1]);
		if(c>=res){
			ri=i;
			res=c;
		}
	}
	cout<<bsti[ri]+1<<" "<<bsti[mm-ri-1]+1<<endl;
}