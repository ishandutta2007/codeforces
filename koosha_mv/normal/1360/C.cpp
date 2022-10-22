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

const int N=5e5+9;

int n,t,x,mark[N];
vector<int> v,z;

int main(){
	cin>>t;
	while(t--){
		fill(mark,mark+200,0);
		v.clear(),z.clear();
		cin>>n;
		f(i,0,n){
			cin>>x;
			if(x%2) v.pb(x);
			else z.pb(x);
		}
		if(v.size()%2==0) cout<<"YES";
		else{
			int ans=0;
			f(i,0,v.size()) mark[v[i]]=1;
			f(i,0,z.size())
				if(mark[z[i]+1] || mark[z[i]-1]) ans=1;
			if(ans) cout<<"YES";
			else cout<<"NO";
		}
		cout<<endl;
	}
}