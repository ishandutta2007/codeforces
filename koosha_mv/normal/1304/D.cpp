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
const int N=2e5+99;
ll n,t,a[N],b[N],k,p,t1;
char s[N];
vector<int> v;
int main(){
	cin>>t;
	f(q,0,t){
		get(n);
		scanf("%s",&s);
		a[n-1]=0,b[n-1]=0;
		f_(i,n-2,0){
			a[i]=0;
			b[i]=0;
			if(s[i]=='<')
				a[i]=a[i+1]+1;
			else
				b[i]=b[i+1]+1;
		}
		k=0,p=n;
		while(k<n){
			t1=p-a[k];
			f(i,0,a[k]+1) cout<<t1+i<<" ";
			k+=a[k]+1;
			p=t1-1;
				
		}
		cout<<endl;
		k=0,p=1;
		while(k<n){
			t1=p+b[k];
			f(i,0,b[k]+1) cout<<t1-i<<" ";
			p=t1+1;
			k+=b[k]+1;
		}
		cout<<endl;
	}
}