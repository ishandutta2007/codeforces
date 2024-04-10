#include <bits/stdc++.h>
#define ll long long
#define Mid ((L+R)>>1)
using namespace std;
typedef pair<int,int> pii;
inline int read(){
	char c;int x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;return x;
}
const int maxn=1000010;
int i,j,k,n,m,a[maxn],S[maxn],L[maxn],R[maxn],top;
ll sum[maxn];
void work(){
	S[top=1]=0;
	for(i=1;i<=n;i++){
		while(a[i]>a[S[top]])top--;
		L[i]=S[top];S[++top]=i;
	}S[top=1]=n+1;
	for(i=n;i>=1;i--){
		while(a[i]>=a[S[top]])top--;
		R[i]=S[top];S[++top]=i;
	}
}
void work2(){
	S[top=1]=0;
	for(i=1;i<=n;i++){
		while(a[i]<a[S[top]])top--;
		L[i]=S[top];S[++top]=i;
	}S[top=1]=n+1;
	for(i=n;i>=1;i--){
		while(a[i]<=a[S[top]])top--;
		R[i]=S[top];S[++top]=i;
	}
}
ll ans=0;
int main() {
	cin>>n;
	for(i=1;i<=n;i++)a[i]=read();
	a[0]=a[n+1]=1e9;work();
	for(i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(i=1;i<=n;i++)ans+=1ll*(R[i]-i)*(i-L[i])*a[i];
	a[0]=a[n+1]=0;work2();
	for(i=1;i<=n;i++)ans-=1ll*(R[i]-i)*(i-L[i])*a[i];
	cout<<ans<<endl;
	//cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
	return 0;
}