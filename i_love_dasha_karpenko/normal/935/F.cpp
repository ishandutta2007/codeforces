#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
const int N = 1e5+7;
const ll INF = 1e18;
int A[N];
struct tnode{
	ll lb,rb,sum,aval;
};
tnode merge(tnode a,tnode b){
	if (a.aval==-1){
		return b;
	}
	if (b.aval==-1){
		return a;
	}
	a.aval = min(a.aval,b.aval);
	a.aval = min(a.aval,max(0ll,a.rb)*2+max(0ll,-b.lb)*2);
	a.sum += b.sum;
	a.rb = b.rb;
	return a;
}
struct tree{
	tnode T[N*2];
	void buildtree(int t,int tl,int tr,int *A){
		if (tl==tr){
			T[t].lb = T[t].rb = A[tl];
			T[t].sum = abs(A[tl]);
			T[t].aval = INF;
			return;
		}
		int tm  = (tl+tr)/2;
		buildtree(t+1,tl,tm,A);
		buildtree(t+(tm-tl+1)*2,tm+1,tr,A);
		T[t] = merge(T[t+1],T[t+(tm-tl+1)*2]);
	}
	void update(int t,int tl,int tr,int pos,int add){
		if (tl>pos || tr<pos){
			return;
		}
		if (tl==tr){
			T[t].lb += add;
			T[t].rb += add;
			T[t].sum = abs(T[t].lb);
			return;
		}
		int tm = (tl+tr)/2;
		update(t+1,tl,tm,pos,add);
		update(t+(tm-tl+1)*2,tm+1,tr,pos,add);
		T[t] = merge(T[t+1],T[t+(tm-tl+1)*2]);
	}
	tnode get(int t,int tl,int tr,int l,int r){
		if (tl>r || l>tr){
			return {-1,-1,-1,-1};
		}
		if (l<=tl && tr<=r){
			return T[t];
		}
		int tm = (tl+tr)/2;
		return merge(get(t+1,tl,tm,l,r),get(t+(tm-tl+1)*2,tm+1,tr,l,r));
	}
} T;
void solve() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i+=1){
		cin>>A[i];
	}
	for(int i = 1;i<n;i+=1){
		A[i] = A[i]-A[i+1];
	}
	T.buildtree(0,1,n-1,A);
	int q;
	cin>>q;
	for(int qe = 1;qe<=q;qe+=1){
		int type;
		cin>>type;
		if (type==1){
			int l,r,x;
			cin>>l>>r>>x;
			tnode ret = T.get(0,1,n-1,max(1,l-1),r);
			if (ret.aval==-1){
				ret.aval = INF;
			}
			ll rv = x*2-ret.aval + T.T[0].sum;
			for(int d = 0;d<2 && d+l<=r;d+=1){
				T.update(0,1,n-1,l+d-1,-x);
				T.update(0,1,n-1,l+d,x);
				rv = max(rv,T.T[0].sum);
				T.update(0,1,n-1,l+d-1,x);
				T.update(0,1,n-1,l+d,-x);
			}
			for(int d = 0;d<2 && r-d>=l;d+=1){
				T.update(0,1,n-1,r-d-1,-x);
				T.update(0,1,n-1,r-d,x);
				rv = max(rv,T.T[0].sum);
				T.update(0,1,n-1,r-d-1,x);
				T.update(0,1,n-1,r-d,-x);
			}
			cout<<rv<<endl;
		}
		else{
			int l,r,x;
			cin>>l>>r>>x;
			T.update(0,1,n-1,l-1,-x);
			T.update(0,1,n-1,r,x);
		}
	}


}
signed main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
//    cin>>t;
    while(t--)
        solve();
}