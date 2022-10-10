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
int i,j,k,n,m;
int a[50010],b[50010],s[400010];
void in(int x,int y){
	char c;
	do c=getchar();
	while(c!='.'&&c!='*');
	if(c=='*')a[x]++,b[y]++;
	s[x*m+y]=(c=='*');
}
int m1[50010],m2[50010],l1,l2;
int main(){
	int t;
	cin>>t;
	while(t--){
		l1=l2=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		cin>>n>>m;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				in(i,j);
		int Max1=0,Max2=0;
		for(i=1;i<=n;i++){
			if(a[i]>Max1){
				l1=0;
				Max1=a[i];
			}
			if(a[i]==Max1)
				m1[++l1]=i;
		}//cout<<endl;
		for(i=1;i<=m;i++){
			if(b[i]>Max2){
				l2=0;
				Max2=b[i];
			}
			if(b[i]==Max2)
				m2[++l2]=i;
		}//cout<<endl;
		int bj=0;
		for(i=1;i<=l1;i++)
			for(j=1;j<=l2;j++){
				int X=m1[i],Y=m2[j];
				if(s[X*m+Y]==0){bj=1;break;}
			}
		cout<<max(n+m-Max1-Max2-bj,0)<<endl;
	}
	return 0;
}