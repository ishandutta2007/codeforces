#include<bits/stdc++.h>
using namespace std;
class segment_tree{
#define mid ((l+r)>>1)
public:
	long long n,ql,qr,qv;
	long long val[1000010<<2],tag[1000010<<2];
	inline void pushup(long long p) {val[p]=max(val[p<<1],val[p<<1|1]);}
	inline void pushdown(long long p) {
		tag[p<<1]+=tag[p],tag[p<<1|1]+=tag[p];
		val[p<<1]+=tag[p],val[p<<1|1]+=tag[p];
		tag[p]=0;
	}
	inline void update(long long p,long long l,long long r){
		if(l>=ql&&r<=qr) return ++val[p],++tag[p],void();
		pushdown(p);
		if(ql<=mid) update(p<<1,l,mid);
		if(qr>mid) update(p<<1|1,mid+1,r);
		pushup(p);
	}
	inline long long query(long long p,long long l,long long r) {
		if(l==r) return l;
		pushdown(p);
		if(val[p<<1|1]>qv) return query(p<<1|1,mid+1,r);
		if(val[p<<1]>qv) return query(p<<1,l,mid);
		return 0;
	}
	inline void build(long long s) {n=s,memset(val,0,sizeof(val)),memset(tag,0,sizeof(tag));}
	inline void update(long long l,long long r) {ql=l,qr=r,update(1,1,n);}
	inline long long query(long long v) {return qv=v,query(1,1,n);}
}sgt;
long long n,cnt,now,ans;
string s;
int main(){
	cin>>n>>s;
	sgt.build(n+1);
	for(long long i=0;i<n;++i) {
		if(s[i]=='0') cnt=0,ans+=now;
		else {
			long long pos=sgt.query(cnt);
			now+=i+1-pos;
			++cnt;
			sgt.update(pos+1,i+1);
			ans+=now;
		}
	} cout<<ans;
	return 0;
}