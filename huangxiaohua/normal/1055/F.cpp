#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,sb;
ll n,m,f[1005000],x,y,res,a,b,c,d;
#define b(x) (1ll<<((x)-1))

#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
inline ll rd()
{
    char c=getchar();ll x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
vector<tuple<int,int,int,int> >v,v1;

int main() {
	ios::sync_with_stdio(0);
	n=rd();m=rd();
	m--;
	for(i=2;i<=n;i++){
		x=rd();y=rd();
		f[i]=(f[x]^y);
	}
	sort(f+1,f+n+1);
	v.push_back({1,n,n+1,n});
	for(i=64;i>=1;i--){
		ll t1=0;y=0;
		a=b=c=d=0;
		t=0;
		for(auto [l,r,l1,r1]:v){
			for(j=l;j<=r+1;j++){
				if((f[j]&b(i))||j>r){a=j-l;b=r-j+1;break;}
			}
			for(j=l1;j<=r1+1;j++){
				if((f[j]&b(i))||j>r1){c=j-l1;d=r1-j+1;break;}
			}
			t1+=a*c*2+b*d*2;
			if(!sb)t1+=a*a+b*b+c*c+d*d;
		}
		if(m>=t1){
			m-=t1;
			res|=b(i);
			t=1;
		}
		a=b=c=d=0;
		for(auto [l,r,l1,r1]:v){
			for(j=l;j<=r+1;j++){
				if((f[j]&b(i))||j>r){a=j-l;b=r-j+1;break;}
			}
			for(j=l1;j<=r1+1;j++){
				if((f[j]&b(i))||j>r1){c=j-l1;d=r1-j+1;break;}
			}
			if(t&&!sb){
				if(a||b)v1.push_back({l,l+a-1,l+a,r});continue;
			}
			if(t){
				if(a||d)v1.push_back({l,l+a-1,l1+c,r1});
				if(b||c)v1.push_back({l+a,r,l1,l1+c-1});
			}
			else{
				if(a||c)v1.push_back({l,l+a-1,l1,l1+c-1});
				if(b||d)v1.push_back({l+a,r,l1+c,r1});
			}
		}
		sb|=t;
		swap(v1,v);v1.clear();
	}
	cout<<res;
}