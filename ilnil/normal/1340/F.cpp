#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=1e5+5,M=1005,bas=1e6+7;
const int mo=998244353,mo2=1e9+9;
int n,k,q,op,l,r;
int a[N],be[N],B;
int _[N],_2[N];
bool yes;
struct has{
	int x,y;
	has(int _x=0,int _y=0){x=_x;y=_y;}
	bool operator!=(const has &b){
		return x!=b.x||y!=b.y;
	}
	has operator-(const has &b){
		return has((x-b.x+mo)%mo,(y-b.y+mo2)%mo2);
	}
	has operator+(const has &b){
		return has((x+b.x)%mo,(y+b.y)%mo2);
	}
};
has mul(has a,int b){
	return has((ll)a.x*_[b]%mo,(ll)a.y*_2[b]%mo2);
}
struct block{
	int l,r;
	int d[M],ds;
	int d2[M],ds2;
	has h[M],h2[M];
	bool wr;
	void build(){
		wr=ds=ds2=0;
		fo(i,l,r)
			if(a[i]>0){
				d[++ds]=a[i];
			}else{
				if(!ds)d2[++ds2]=-a[i];else{
					if(d[ds]==-a[i])--ds;
					else{
						wr=1;
						break;
					}
				}
			}
		h[ds+1]=has();
		fd(i,1,ds)h[i]=mul(h[i+1],1)+has(d[i],d[i]);
		fo(i,1,ds2)h2[i]=mul(h2[i-1],1)+has(d2[i],d2[i]);
	}
}b[M];
int ss;
struct nod{
	int a,r,one;
}st[M*6];
has getr(has *h,int r,int len){
	return h[r-len+1]-mul(h[r+1],len);
}
has getl(has *h,int l,int len){
	return h[l+len-1]-mul(h[l-1],len);
}
int push(int l,int r=0){
	if(!yes)return 0;
	if(r==0){
		if(b[l].wr)return yes=0;
		int p=1;
		for(;p<=b[l].ds2;){
			if(!ss)return yes=0;
			if(st[ss].one){
				if(b[l].d2[p]!=st[ss].a)return yes=0;
				++p;
				--ss;
			}else{
				int len=min(b[l].ds2-p+1,st[ss].r);
				if(getr(b[st[ss].a].h,st[ss].r,len)!=getl(b[l].h2,p,len))return yes=0;
				p+=len;
				if(!(st[ss].r-=len))--ss;
			}
		}
		if(b[l].ds)st[++ss]=(nod){l,b[l].ds,0};
	}else{
		fo(i,l,r)
			if(a[i]>0){
				st[++ss]=(nod){a[i],0,1};
			}else{
				if(!ss)return yes=0;
				if(st[ss].one){
					if(st[ss].a!=-a[i])return yes=0;
					--ss;
				}else{
					if(b[st[ss].a].d[st[ss].r]!=-a[i])return yes=0;
					if(!--st[ss].r)--ss;
				}
			}
	}
return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	fo(i,1,n)cin>>a[i];
	_[0]=1;_2[0]=1;
	fo(i,1,n)_[i]=(ll)_[i-1]*bas%mo,_2[i]=(ll)_2[i-1]*bas%mo2;
	B=500;
	fo(i,1,n)be[i]=i/B+1,b[be[i]].r=i,(b[be[i]].l?0:b[be[i]].l=i);
	fo(i,1,be[n])b[i].build();
	cin>>q;
	fo(ts,1,q){
		cin>>op>>l>>r;
		if(op==1){
			a[l]=r;
			b[be[l]].build();
		}else{
			yes=1;
			ss=0;
			if(be[l]==be[r])push(l,r);
			else{
				push(l,b[be[l]].r);
				fo(i,be[l]+1,be[r]-1)push(i);
				push(b[be[r]].l,r);
			}
			if(ss)yes=0;
			printf(yes?"Yes\n":"No\n");
		}
	}
}