#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pr printf
#define P push
#define PB push_back
#define F front
#define T top
#define MP make_pair
#define Fi first
#define Se second
using namespace std;
inline long long gcd(long long a,long long b){return b==0?a:gcd(b,a%b);}
inline long long lcm(long long a,long long b){return a/gcd(a,b)*b;}
inline void read(long long &x){
	char ch;
	do ch=getchar();while(ch<48||ch>57);
	x=0;while(ch<=57&&ch>=48){x=x*10+ch-48;ch=getchar();}
}
inline void read(int &x){
	char ch;
	do ch=getchar();while(ch<48||ch>57);
	x=0;while(ch<=57&&ch>=48){x=x*10+ch-48;ch=getchar();}
}
int i,j,k,n,m,na,nb,a,b,ans;
int main(){
	cin>>n;
	ans=1;
	na=nb=0;
	for(i=1;i<=n;i++){
		scanf("%d%d",&a,&b);
		if(na!=nb)
			ans+=max(min(a,b)-max(na,nb)+1,0);
		else
			ans+=max(min(a,b)-max(na,nb),0);
		na=a;nb=b;
	}
	cout<<ans<<endl;
	return 0;
}