#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll
//#define endl '\n'

// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// print number in binary -> cout << bitset<20>(n);

const int N=1000100,inf=1e18;
int n,cnt1,res=inf;
int a[N];
int tr(int p){
	int res=0,cargo=0;
	for(int i=0;i<n;++i){
		res+=abs(cargo);
		if(a[i]+cargo<=0){
			cargo+=a[i];
			continue;
		}
		if(2*((a[i]+cargo)%p)<p) // forward
			cargo=(a[i]+cargo)%p;
		else cargo=(a[i]+cargo)%p-p;
	}
//	cerr<<p<<" "<<res<<endl;
	return res;
}
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<n;++i)cnt1+=a[i];
	int cnt2=cnt1;
	for(int i=2;i*i<=cnt2;++i){
		if(cnt2%i==0)res=min(res,tr(i));
		while(cnt2%i==0)cnt2/=i;
	}
	if(cnt2!=1)res=min(res,tr(cnt2));
	if(res==inf)cout<<-1<<endl;
	else cout<<res<<endl;
}