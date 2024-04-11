#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
const int N=2e5+9;
ll t,a,b,r,k;
int main(){
	cin>>t;
	f(q,0,t){
		r=0;
		k=0;
		cin>>a>>b;
		while(b>0){
			if(b%10!=9)
				k=1;
			r++;
			b/=10;
		}
		cout<<(r-k)*a<<endl;
	}
}