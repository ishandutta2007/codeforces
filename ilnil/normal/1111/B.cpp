#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;i++)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;i--)
#define ll long long
#define db double
using namespace std;
const int N=1e5+5;
int n,k,m,a[N];
ll su[N];
db ans;
void R(int &n){
	char c;for(n=0;(c=getchar())<'0'||c>'9';);
	for(;c<='9'&&c>='0';c=getchar())n=n*10+c-48;
}
int pd(char x){
	return x=='a'||x=='e'||x=='i'||x=='o'||x=='u';
}
int main(){
	scanf("%d%d%d",&n,&k,&m);
	fo(i,1,n)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	fd(i,1,n)su[i]=su[i+1]+a[i];
	fo(i,0,min(n-1,m)){
		ans=max(ans,(su[i+1]+min((ll)k*(n-i),(ll)m-i))/(db)(n-i));
	}
	printf("%.20f",ans);
}