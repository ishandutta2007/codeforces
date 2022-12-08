#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
int n, a[N];

vector<int> zeros;

int lft[N], rgt[N];

#define mid ((l+r)>>1)	

int tg[N<<2], mx[N<<2];
inline void pushdown(int x,int l,int r){
	if(tg[x]!=0)if(l^r){
		mx[x<<1]+=tg[x],mx[x<<1|1]+=tg[x];
		tg[x<<1]+=tg[x],tg[x<<1|1]+=tg[x];
	}
	tg[x] = 0;
}
inline void modify(int x,int l,int r,int ql,int qr,int s){
	pushdown(x,l,r);
	if(ql<=l&&qr>=r){
		tg[x]+=s,mx[x]+=s;return;
	}
	if(ql<=mid)modify(x<<1,l,mid,ql,qr,s);
	if(qr>mid)modify(x<<1|1,mid+1,r,ql,qr,s);
	mx[x] = max(mx[x<<1],mx[x<<1|1]);
}
inline void build(int x,int l,int r){
	tg[x] = 0;
	if(l==r){mx[x] = -n-l;return ;}
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
	mx[x] = max(mx[x<<1], mx[x<<1|1]);
}
#undef mid

inline void Main(){
	cin >> n;
	zeros.clear();
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0)zeros.push_back(i);
	}
	for(int i=1;i<=n;i++)lft[i] = rgt[i] = 0;
	int midpoint = zeros.size()?zeros[zeros.size() / 2]:1;
	for(int i=1,P=0;i<=midpoint;i++)
		if(!a[i])++P;
		else lft[a[i]]=P;
	for(int i=n,P=0;i>midpoint;i--)
		if(!a[i])++P;
		else rgt[a[i]]=P;
	vector<vector<int> > opt(n);
	build(1,0,n);
	for(int i=1;i<=n;i++){
		opt[rgt[i]].push_back(lft[i]);
	}
	for(int r=n-1;~r;--r){
		for(auto l: opt[r]){
			modify(1,0,n,l,n,1);
		}
	}
	int maxm = zeros.size()/2;
	// cout << zeros.size() << endl;
	// for(int i=0;i<=(int)zeros.size();i++)for(int j=0,sz=n;j<=(int)zeros.size();j++){
	// 	for(auto l:opt[j])if(l<=i)sz--;
	// 	maxm = min(maxm, i+j+sz);
	// 	// if(i+j+sz<=50)cout << i << ":" << j << ":" << i+j+sz << endl;
	// }
	for(int r=n-1;~r;--r){
		int mm = mx[1];
		maxm = min(maxm, -mm + r);
		// cout << r << ":" << -mm + r << endl;
		for(auto l: opt[r]){
			modify(1,0,n,l,n,-1);
		}
	}
	cout << maxm << endl;
}

int main()
{
	int T;cin >> T;
	while(T--){
		Main();
	}
}
/* 
1
200
37 13 42 24 17 0 0 0 0 36 0 8 25 25 31 4 0 0 0 0 4 0 5 14 16 49 1 0 15 0 0 0 0 0 11 43 25 0 0 1 0 0 0 0 41 25 0 16 0 0 40 16 5 8 43 39 39 0 0 12 50 0 34 12 0 0 0 30 50 5 0 14 16 0 0 0 0 16 0 0 49 26 22 34 20 40 0 0 43 31 14 0 0 25 0 25 26 25 0 32 0 4 0 21 0 0 43 0 36 48 0 0 31 11 25 37 42 19 15 0 25 0 0 10 36 0 0 0 11 4 16 34 4 0 0 14 18 37 0 0 32 0 0 0 37 0 24 4 0 0 5 0 0 0 0 0 39 38 0 0 2 0 21 0 49 0 33 6 12 43 33 0 27 2 9 24 0 0 41 12 0 0 0 0 22 0 47 31 26 0 0 45 0 11 0 0 11 0 0 0
 */