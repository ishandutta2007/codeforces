#include<bits/stdc++.h>
#define rgi register int
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
typedef long long ll;
using namespace std;
inline void read(){}template <typename T,typename... Ts> inline void read(T& A,Ts&... As){
	T x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	A=x*f,read(As...);
}
inline void write(char a){putchar(a);}
template <typename T> inline void write(T a){
	if(a<0ll)putchar('-'),a=-a;
	if(a>9ll)write(a/10ll);
	putchar(a%10ll+'0');
}
template <typename T,typename... Ts> inline void write(T A,Ts... As){write(A),write(As...);}
const int N=100010;
int n,a[N];
int id,id1;
int ans;
int f1,f2,mi[N],mx[N];
inline int qry(int t,int i,int j,int x){
	cout<<"? "<<t<<' '<<i<<' '<<j<<' '<<x<<endl;
	cin>>ans;return ans;
}
inline void qrymx(int i,int j){
	mx[i]=qry(1,i,j,n-1);
	if(mx[i]==n)id=j,f2=1;
	if(mx[i]==n-1&&qry(1,j,i,n-1)==n)id=i,f2=1;
}
void qrymi(int i,int j){
	mi[i]=qry(2,i,j,1);
	if(mi[i]==1)id1=i,f1=1;
	if(mi[i]==2&&qry(2,j,i,1)==1)id1=j,f1=1;
}
void getans(int i,int j){
	if(i==id1)return a[i]=1,qry(1,i,j,n-1),a[j]=ans,void();
	if(i==id)return a[i]=n,qry(2,j,i,1),a[j]=ans,void();
	if(j==id1)return a[j]=1,qry(1,j,i,n-1),a[i]=ans,void();
	if(j==id)return a[j]=n,qry(2,i,j,1),a[i]=ans,void();
	ans=qry(1,i,j,mi[i]);
	if(ans==mi[i])a[i]=mx[i],a[j]=mi[i];
	else a[i]=mi[i],a[j]=mx[i];
}
signed main(){
	int t;
	read(t);
	while(t--){
		read(n),id=id1=f1=f2=0;
		for(rgi i=1;i<n;i+=2)qrymx(i,i+1);
		qrymx(n,1);
		for(rgi i=1;i<n;i+=2)qrymi(i,i+1);
		qrymi(n,1);
		for(rgi i=1;i<n;i+=2)getans(i,i+1);
		getans(n,1),cout<<"! ";
		for(rgi i=1;i<=n;++i)cout<<a[i]<<" ";
		cout<<endl;
	}
	return 0;
}