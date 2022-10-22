#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
const int N=5e5+9,sq=800;
int a[N],q,ans[sq+2][sq+2],t,x,y;
void update(int x,int y){
	f(i,1,sq+1)
		ans[i][x%i]+=y;
}
int main(){
	cin>>q;
	f(i,0,q){
		gett(t);
		Gett(x,y);
		if(t==1){
			a[x]+=y;
			update(x,y);
		}
		else{
			if(x<sq)
				cout<<ans[x][y]<<endl;
			else{
				int res=0;
				for(int j=y;j<N;j+=x)
					res+=a[j];
				cout<<res<<endl;
			}
		}
	}
}