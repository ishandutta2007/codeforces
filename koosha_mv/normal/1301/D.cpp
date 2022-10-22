#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=30009;
ll n,m,k,ans[N],s;
string s1;
string u="U",r="R",d="D",l="L",anss[N][4];
int main(){
	cin>>m>>n>>k;
	if(k>4*m*n-2*n-2*m){cout<<"NO";return 0;}
	if(m==1){
		ans[0]=min(n-1,k);
		k-=min(n-1,k);
		anss[0][0]=r;
		s++;
		if(k>0){
		ans[1]=min(n-1,k);
		k-=min(n-1,k);
		anss[1][0]=l;
		s++;
		}
		cout<<"YES"<<endl;
		cout<<s<<endl;
		f(i,0,s){
			s1="";
			s1=s1+anss[i][0];
			s1=s1+anss[i][1];
			s1=s1+anss[i][2];
			cout<<ans[i]<<" "<<s1<<endl;
		}
		return 0;
	}
	f(i,0,n-1){
		if((m-1)*3<=k){
			ans[s]=m-1;
			anss[s][0]=d,anss[s][1]=r,anss[s][2]=l;
			k-=(m-1)*3;
			s++;
		}
		else{
			if(k>=3){
			ans[s]=k/3,anss[s][0]=d,anss[s][1]=r,anss[s][2]=l;
			s++;
			}
			k=k%3;
			if(k>=1){
				ans[s]=1;
				anss[s][0]=d;
				if(k>=2)	
					anss[s][1]=r;
				s++;
			}
			k=0;
			break;
		}
		if(k==0) break;
		if(k<m){
			ans[s]=k;
			anss[s][0]=u;
			k=0;
			s++;
		}
		else{

			ans[s]=m-1;
			anss[s][0]=u;
			s++;
			ans[s]=1;
			anss[s][0]=r;
			k-=m;
			s++;
		}
		if(k==0) break;
	}
	if(k>0){
		ans[s]=min(k,m-1);
		anss[s][0]=d;
		s++;
		k-=min(k,m-1);
		if(k>0){
			ans[s]=min(k,m-1);
			anss[s][0]=u;
			s++;
			k-=min(k,m-1);
		}
	}
	if(k>0){
		ans[s]=min(k,n-1);
		anss[s][0]=l;
		k-=min(n-1,k);
		s++;
	}
		cout<<"YES"<<endl;
		cout<<s<<endl;
		f(i,0,s){
			s1="";
			s1=s1+anss[i][0];
			s1=s1+anss[i][1];
			s1=s1+anss[i][2];
			cout<<ans[i]<<" "<<s1<<endl;
		}
}