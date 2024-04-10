#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define li 1000000001
int i,j,k,n,m,t,sb,su,tmp,lst;
struct SB{
	int ls[10005000],rs[10005000],it=1,f[10005000],k;
	#define md ((l+r)>>1)
	#define upd() if(!ls[id]){ls[id]=++it;}if(!rs[id]){rs[id]=++it;}
	void add(int id,int l,int r,int x){
		if(l==r){f[id]++;return;}
		upd();
		if(x<=md){add(ls[id],l,md,x);}
		else{add(rs[id],md+1,r,x);}
		f[id]=f[ls[id]]+f[rs[id]];
	}
	int get(int id,int l,int r,int su,int qu){
		if(l==r)return l;
		upd();
		k=su+md-f[ls[id]];
		if(k>qu){return get(ls[id],l,md,su,qu);}
		else{return get(rs[id],md+1,r,su-f[ls[id]],qu);}
	}
	int get2(int id,int l,int r,int x){
		if(r<=x)return f[id];
		upd();
		if(x<=md)return get2(ls[id],l,md,x);
		return f[ls[id]]+get2(rs[id],md+1,r,x);
	}
}st;
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>sb;sb++;
		i=st.get(1,1,li+1000,su,sb-1);
		j=st.get(1,1,li+1000,su,sb);
		st.add(1,1,li+1000,i);st.add(1,1,li+1000,j);
		su++;
		cin>>n;
		while(n--){
			cin>>k;
			k=(lst+k)%li;
			lst=-st.get2(1,1,li+1000,k+1)+k+su;
			cout<<lst<<'\n';
		}
	}
}