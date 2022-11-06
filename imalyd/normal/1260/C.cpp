#include<bits/stdc++.h>
using namespace std;
namespace io{
	const int l=1<<20;
	char buf[l],*s,*t,c;
	inline void gc(){
		if(s==t){
			t=(s=buf)+fread(buf,1,l,stdin);
			c=s==t?EOF:*s++;
		}else c=*s++;
	}
	template<class IT>inline void gi(IT &x){
		x=0;gc();while(c<'0'||c>'9')gc();
		while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48);gc();}
	}
};
using io::gi;
inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline void ac(){
	int a,b,g,k;
	gi(a);gi(b);gi(k);
	if(a>b)swap(a,b);
	g=gcd(b,a);a/=g;b/=g;
	if((a+b-2)/a<k&&k!=1)puts("OBEY");else puts("REBEL");
}
int main(){
	//FASTIO
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	
	//CIN/COUT
	//ifstream in ("a.in" );cin .rdbuf(in .rdbuf());
	//ofstream out("a.out");cout.rdbuf(out.rdbuf());
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	
	int T;
	gi(T);
	while(T--)ac();
	return 0;
}