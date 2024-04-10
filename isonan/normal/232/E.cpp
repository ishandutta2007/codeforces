#include <bits/stdc++.h>

namespace nqio{const unsigned R=4e5,W=4e5;char*a,*b,i[R],o[W],*c=o,*d=o+W,h[40],*p=h,y;bool s;struct q{void r(char&x){x=a==b&&(b=(a=i)+fread(i,1,R,stdin),a==b)?-1:*a++;}void f(){fwrite(o,1,c-o,stdout);c=o;}~q(){f();}void w(char x){*c=x;if(++c==d)f();}q&operator>>(char&x){do r(x);while(x<=32);return*this;}q&operator>>(char*x){do r(*x);while(*x<=32);while(*x>32)r(*++x);*x=0;return*this;}template<typename t>q&operator>>(t&x){for(r(y),s=0;!isdigit(y);r(y))s|=y==45;if(s)for(x=0;isdigit(y);r(y))x=x*10-(y^48);else for(x=0;isdigit(y);r(y))x=x*10+(y^48);return*this;}q&operator<<(char x){w(x);return*this;}q&operator<<(char*x){while(*x)w(*x++);return*this;}q&operator<<(const char*x){while(*x)w(*x++);return*this;}template<typename t>q&operator<<(t x){if(!x)w(48);else if(x<0)for(w(45);x;x/=10)*p++=48|-(x%10);else for(;x;x/=10)*p++=48|x%10;while(p!=h)w(*--p);return*this;}}qio;}using nqio::qio;
typedef unsigned long long ull;
int lim;
struct bitset{
	ull v[8];
	void clear(){
		memset(v,0,lim<<3);
	}
	void set(int x){
		v[x>>6]|=1ull<<((1ull*x)&63ull);
	}
	bitset& operator|=(const bitset &a){
		for(int i=0;i<lim;++i)v[i]|=a.v[i];
		return *this;
	}
}L[501][501],R[501][501];
bool operator&(const bitset &a,const bitset &b){
	for(int i=0;i<lim;++i)if(a.v[i]&b.v[i])return 1;
	return 0;
}
bool map[501][501];
int n,m,q;
struct query{
	int x1,y1,x2,y2,ord;
};
int ans[600001];
void solve(int X1,int X2,int Y1,int Y2,std::vector<query>&vec){
	if(X1>X2||Y1>Y2||vec.empty())return;
	std::vector<query>Lv,Rv;
	if(X2-X1+1>=Y2-Y1+1){
		int mid=(X1+X2)>>1;
		lim=(Y2-Y1+64)>>6;
		for(int i=mid;i>=X1;--i)
			for(int j=Y2;j>=Y1;--j){
				if(!map[i][j])continue;
				L[i][j].clear();
				if(i==mid&&map[i][j])L[i][j].set(j-Y1);
				if(i!=mid&&map[i+1][j])L[i][j]|=L[i+1][j];
				if(j!=Y2&&map[i][j+1])L[i][j]|=L[i][j+1];
			}
		for(int i=mid;i<=X2;++i)
			for(int j=Y1;j<=Y2;++j){
				if(!map[i][j])continue;
				R[i][j].clear();
				if(i==mid&&map[i][j])R[i][j].set(j-Y1);
				if(i!=mid&&map[i-1][j])R[i][j]|=R[i-1][j];
				if(j!=Y1&&map[i][j-1])R[i][j]|=R[i][j-1];
			}
		for(int i=0;i<vec.size();++i)
			if(vec[i].x1>mid)Rv.push_back(vec[i]);
			else if(vec[i].x2<mid)Lv.push_back(vec[i]);
			else ans[vec[i].ord]=L[vec[i].x1][vec[i].y1]&R[vec[i].x2][vec[i].y2];
		solve(X1,mid-1,Y1,Y2,Lv);
		solve(mid+1,X2,Y1,Y2,Rv);
	}
	else{
		int mid=(Y1+Y2)>>1;
		lim=(X2-X1+64)>>6;
		for(int i=mid;i>=Y1;--i)
			for(int j=X2;j>=X1;--j){
				if(!map[j][i])continue;
				L[j][i].clear();
				if(i==mid&&map[j][i])L[j][i].set(j-X1);
				if(i!=mid&&map[j][i+1])L[j][i]|=L[j][i+1];
				if(j!=X2&&map[j+1][i])L[j][i]|=L[j+1][i];
			}
		for(int i=mid;i<=Y2;++i)
			for(int j=X1;j<=X2;++j){
				if(!map[j][i])continue;
				R[j][i].clear();
				if(i==mid&&map[j][i])R[j][i].set(j-X1);
				if(i!=mid&&map[j][i-1])R[j][i]|=R[j][i-1];
				if(j!=X1&&map[j-1][i])R[j][i]|=R[j-1][i];
			}
		for(int i=0;i<vec.size();++i)
			if(vec[i].y1>mid)Rv.push_back(vec[i]);
			else if(vec[i].y2<mid)Lv.push_back(vec[i]);
			else ans[vec[i].ord]=L[vec[i].x1][vec[i].y1]&R[vec[i].x2][vec[i].y2];
		solve(X1,X2,Y1,mid-1,Lv);
		solve(X1,X2,mid+1,Y2,Rv);
	}
}
char str[501];
int main(){
	qio>>n>>m;
	for(int i=1;i<=n;++i){
		qio>>str+1;
		for(int j=1;j<=m;++j)
			map[i][j]=(str[j]=='.');
	}
	std::vector<query>vec;
	qio>>q;
	for(int i=1,x1,y1,x2,y2;i<=q;++i){
		qio>>x1>>y1>>x2>>y2;
		vec.push_back((query){x1,y1,x2,y2,i});
	}
	solve(1,n,1,m,vec);
	for(int i=1;i<=q;++i)
		if(ans[i])puts("Yes");
		else puts("No");
}