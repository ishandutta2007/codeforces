//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=2e3+5,mod=1e9+7;
int nx,ny;
struct point{int x,y,c;}a[maxn];
int wx[maxn],wy[maxn];
vec tx[maxn],ty[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
multiset<int> s[maxn];
int lst[maxn];
inline int add(int x){return (x>=mod)?x-mod:x;}
inline int sub(int x){return (x<0)?x+mod:x;}
int sum[4*maxn],val[4*maxn],mn[4*maxn],laz[4*maxn];
void build(int k,int l,int r){
	if(l==r){val[k]=wy[l]-wy[l-1];return ;}
	int mid=l+((r-l)>>1);
	build(k<<1,l,mid),build(k<<1|1,mid+1,r);
	val[k]=val[k<<1]+val[k<<1|1];
	return ;
}
void add_laz(int k,int v){sum[k]=1ll*val[k]*v%mod;mn[k]=laz[k]=v;return ;}
void pushdown(int k){
	if(!laz[k])return ;
	add_laz(k<<1,laz[k]),add_laz(k<<1|1,laz[k]);
	laz[k]=0;
	return ;
}
void cover(int k,int l,int r,int x,int y,int v){
	if(l>y||r<x)return ;
	if(l>=x&&r<=y){add_laz(k,v);return ;}
	int mid=l+((r-l)>>1);
	pushdown(k);
	cover(k<<1,l,mid,x,y,v);cover(k<<1|1,mid+1,r,x,y,v);
	sum[k]=add(sum[k<<1]+sum[k<<1|1]);
	mn[k]=min(mn[k<<1],mn[k<<1|1]);
	return ;
}
int find(int k,int l,int r,int v){
	if(l==r)return l;
	int mid=l+((r-l)>>1);pushdown(k);
	if(mn[k<<1|1]<=v)return find(k<<1|1,mid+1,r,v);
	return find(k<<1,l,mid,v);
}
void modify(int l,int r,int v){
	if(v<mn[1])return ;
	int pos=find(1,1,ny,v);
	r=min(r,pos);if(l>r)return ;
	cover(1,1,ny,l,r,v);
	return ;
}
int main(){
    int n,k,L;
	n=read();k=read();L=read();
	for(int i=1;i<=n;i++){
		int x,y,c;
		x=read();y=read();c=read();
		a[i]=(point){x,y,c};
		wx[i]=x,wy[i]=y;
	}
	sort(wx+1,wx+n+1);nx=unique(wx+1,wx+n+1)-wx-1;wx[nx+1]=L,wx[0]=-1;
	sort(wy+1,wy+n+1);ny=unique(wy+1,wy+n+1)-wy-1;wy[ny+1]=L,wy[0]=-1;
	for(int i=1;i<=n;i++){
		int x=lower_bound(wx+1,wx+nx+1,a[i].x)-wx;
		int y=lower_bound(wy+1,wy+ny+1,a[i].y)-wy;
		a[i].x=x,a[i].y=y;
		tx[x].eb(i);ty[y].eb(i);
	}
	int res=0;
	build(1,1,ny);
	for(int i=1;i<=k;i++)s[i].insert(ny+1),s[i].insert(0);
	for(int i=1;i<=nx;i++){
		multiset<int> st;st.clear();
		for(int p=1;p<=k;p++)st.insert(ny+1),lst[p]=ny+1;
		for(int j=ny;j>=1;j--){
			for(auto id:ty[j]){
				if(a[id].x<i)continue;
				st.erase(st.find(lst[a[id].c]));
				lst[a[id].c]=j;st.insert(j);
				s[a[id].c].insert(j);
			}
			cover(1,1,ny,j,j,wy[*st.rbegin()]);
		}
		for(int j=nx;j>=i;j--){
			int aux=sub(1ll*(wy[ny]+1)*L%mod-sum[1]);
			res=add(res+1ll*(wx[i]-wx[i-1])*(wx[j+1]-wx[j])%mod*aux%mod);
			for(auto id:tx[j]){
				int c=a[id].c;
				assert(s[c].find(a[id].y)!=s[c].end());
				s[c].erase(s[c].find(a[id].y));
				if(s[c].find(a[id].y)!=s[c].end())continue;
				auto it=s[c].upper_bound(a[id].y);
				int pre,nxt;nxt=*it;it--;pre=*it;
				modify(pre+1,a[id].y,wy[nxt]);
			}
		}
	}
	printf("%d\n",res);
    return 0;
}