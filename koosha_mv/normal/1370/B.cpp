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
 
const int N=5e5+99;
 
int n,t,a[N];
vector<int> fr,z;
 
int main(){
	cin>>t;
	while(t--){
		fr.clear(),z.clear();
		cin>>n;
		int ans=n-1;
		f(i,0,2*n){
			gett(a[i]);
			if(a[i]%2) fr.pb(i+1);
			else z.pb(i+1);
		}
		if(int(fr.size())%2)
			fr.pop_back(),z.pop_back();
		else{
			if(fr.size()>1)
				fr.pop_back(),fr.pop_back();
			else
				z.pop_back(),z.pop_back();
		}
		for(int i=0;i<z.size();i+=2)
			cout<<z[i]<<" "<<z[i+1]<<endl;
		for(int i=0;i<fr.size();i+=2)
			cout<<fr[i]<<" "<<fr[i+1]<<endl;
	}
}