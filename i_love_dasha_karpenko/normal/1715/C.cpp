//#prama GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pp;
#define endl '\n';
const int N = 2e5+7;
int A[N],n,m;

ll get(int pos){
	if (pos<=1 || pos>n || A[pos-1]==A[pos]){
		return 0;
	}
	return ll(n-pos+1)*(pos-1);
}
ll add(int pos,int cof){
	return (get(pos)+get(pos+1))*cof;
}
void solve(){
	cin>>n>>m;
	for(int i = 1;i<=n;i+=1){
		cin>>A[i];
	}
	ll res = 0;
	for(int i = 2;i<=n;i+=1){
		res += get(i);
	}
	for(int qe = 1;qe<=m;qe+=1){
		int pos,val;
		cin>>pos>>val;
		res += add(pos,-1);
//			cout<<"GDB "<<add(pos,-1)<<' ';
		A[pos] = val;
		res += add(pos,1);
//		cout<<add(pos,1)<<endl;
		cout<<res+ll(n)*(n+1)/2<<endl;
	}
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt = 1;
//	cin>>tt;
	while(tt--){
		solve();
	}
}