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
ll i,j,k,n,m,X1,Y1,X2,Y2;
ll ans;
int main(){
	cin>>X1>>Y1>>X2>>Y2;
	ans=(X1+2)*(Y1+Y2+2)-X1*(Y1+Y2);
	cout<<ans<<endl;
	return 0;
}