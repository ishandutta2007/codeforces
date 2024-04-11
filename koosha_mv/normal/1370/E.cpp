#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod;
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=1e6+2;

int n,e,c=1,mx,mn,a[N];
string s,t;

int main(){
	cin>>n>>s>>t;
	f(i,0,n){
		if(s[i]!=t[i]){
			if(s[i]=='1')
				a[c++]=1,e++;
			else
				a[c++]=-1,e--;
		}
	}
	if(e!=0) return cout<<-1,0;
	f(i,1,c){
		a[i]+=a[i-1];
		maxm(mx,a[i]);
		minm(mn,a[i]);
	}
	cout<<mx+-1*mn;
}