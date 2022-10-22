#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=3e6+99;

int n,sz,a[N],b[N],mark[N];
vector<int> v;

bool check(int x){
	fill(mark,mark+(1<<x),0);
	sz=1;
	f(i,0,n)
		if(!mark[a[i]]){
			v.pb(a[i]);
			f(j,1,sz+1)
				b[j+sz]=b[j]^a[i],mark[b[j+sz]]=1;
			sz*=2;
		}
	if(v.size()==x)
		return 1;
	return 0;
}

int main(){
	cin>>n;
	f(i,0,n) cin>>a[i];
	f_(i,20,0){
		v.clear();
		if(check(i)){
			cout<<i<<endl;
			int prev=0;
			f(j,1,(1<<i)){
				cout<<prev<<" ";
				int c=j;
				for(int k=0;1;k++){
					if(c%2){
						prev=prev^v[k];
						break;
					}
					c/=2;
				}
			}
			cout<<prev<<" ";
			return 0;
		}
	}
}