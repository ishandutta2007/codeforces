#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0;do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=1000010;
int i,j,k,n,m,T,a[maxn],b[maxn],sa[maxn],sb[maxn];
bool check(int x){
	int sum=n+x,del=sum/4;
	int S1=100*min(sum-del,x)+(sum-del>x?sa[sum-del-x]:0);
	int S2=sb[min(sum-del,n)];
	//cout<<sum<<' '<<del<<' '<<S1<<' '<<S2<<' '<<sum-del-x<<' '<<sa[sum-del-x]<<endl;
	return S1>=S2;
}
bool cmp(int a,int b){return a>b;}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++)a[i]=read();
		for(i=1;i<=n;i++)b[i]=read();
		sort(a+1,a+1+n,cmp);sort(b+1,b+1+n,cmp);
		for(i=1;i<=n;i++)sa[i]=sa[i-1]+a[i];
		for(i=1;i<=n;i++)sb[i]=sb[i-1]+b[i];
		int L=0,R=2*n;
		while(L<=R){
			int Mid=L+R>>1;
			if(check(Mid))R=Mid-1;
			else L=Mid+1;
		}printf("%d\n",R+1);
	}
}