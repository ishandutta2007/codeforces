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

const int N=105;

int n,s,t,k,mark[N],a[N],b[N],p;

int main(){
	cin>>t;
	f(q,0,t){
		fill(mark,mark+N,0);
		s=0;
		Gett(n,k);
		f(i,0,n){
			gett(a[i]);
			if(mark[a[i]]==0){
				mark[a[i]]++;
				s++;
			}
		}
		if(s>k) cout<<-1<<endl;
		else{
			p=0;
			f(i,1,n+1)
				if(mark[i])
					b[p++]=i;
			while(p<k)
				b[p++]=1;
			cout<<p*n<<endl;
			f(i,0,n)
				print(b,p);
		}
	}
}