#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e5+9;

int n,t,k,mark[170],a[N],p,mx;
string s;

int main(){
	cin>>t;
	f(q,0,t){
		fill(mark+97,mark+150,0);
		Gett(n,k);
		cin>>s;
		mx=0;
		f(i,0,n){
			mark[s[i]]++;
			a[i]=s[i];
			maxm(mx,int(s[i]));
		}
		sort(a,a+n);
		p=1;
		if(a[0]!=a[k-1]) cout<<char(a[k-1]);
		else{
			if(a[0]==a[n-1]){
				f(i,0,n/k+(n%k>0)) cout<<char(a[0]);
			}
			else{
				cout<<char(a[0]);
				f(i,k+1,n)
					if(a[i]!=a[i-1]) p++;
				if(p==1)
				 	f(i,0,(n-k)/k+((n-k)%k>0))	
						cout<<char(a[k]);
				else
					f(i,k,n)
						cout<<char(a[i]);
			}
		}
		cout<<endl;
	}
}