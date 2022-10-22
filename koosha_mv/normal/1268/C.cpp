#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
const int N=2e5+9;
ll mid[N],a[N],mark[N],k,f1[N][2],n,g[N],h[N],p,ct,cn,tvn=1,tedad[N*4];string s,s2;
ll saghf(ll x){return (x/2)+(x%2);}
string binary(int m,int k){
	string g="";
	f(i,0,k){
		g+=char((m%2)+'0');
		m=m/2;
	}
	return g;}
int main(){
	cin>>n;cn=n;
	f(i,1,n+1) scanf("%I64d",&a[i]),mark[a[i]]=i,f1[i][0]=i-1,f1[i][1]=i+1;
	k=saghf(n);
	f_(i,n,1){
		mid[i]=k;
		if(i%2==0){
			if(mark[i]<=k)
				k=f1[k][1];
		}
		else{
			if(mark[i]>=k)
				k=f1[k][0];
		}
		f1[f1[mark[i]][0]][1]=f1[mark[i]][1];
		f1[f1[mark[i]][1]][0]=f1[mark[i]][0];
	}
	k=0;
	f(i,2,n){
		if(i%2==0){
			if(mid[i]==mid[i-1])
				g[i]=g[i-1]+(mark[i]-mid[i])-(i/2);
			else
				g[i]=g[i-1]+(mid[i-1]-mid[i])+(mid[i]-mark[i])-((i/2));
		}
		else{
			if(mid[i]==mid[i-1])
				g[i]=g[i-1]+(mid[i]-mark[i])-(i/2);
			else
				g[i]=g[i-1]+(mark[i]-mid[i])-(i/2);
		}
	}
	f(i,1,(n+3)/2){
		swap(a[i],a[n+1-i]);
		a[i]=n+1-a[i];a[n+1-i]=n+1-a[n+1-i];
	}
	if(n%2==1) a[(n+1)/2]=n+1-a[(n+1)/2];
	while(cn){
		k++;
		cn/=2;
		tvn*=2;
	}tvn/=2;
	f(i,1,n+1){
		s=binary(a[i],k);p=0;ct=tvn;
		ll t=0,m=tvn*2-a[i],p1=tvn*2;s2=binary(m,k);
		f_(j,k-1,0){
			if(s2[j]=='1'){
				p1-=ct;
				t+=tedad[p1];	
			}
			ct/=2;
		}
		h[n+1-a[i]]=t;
		ct=tvn;
		f_(j,k-1,0){
			if(s[j]=='1'){
				p+=ct;
				tedad[p]++;
			}
			ct/=2;
		}
	}
	f(i,1,n+1){h[i]+=h[i-1];cout<<h[i]+g[i]<<" ";}
}