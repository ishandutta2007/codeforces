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

const int N=5e5+99;

int n,t,a1[N],a2[N],a3[N];
string s;

bool check(int l,int r){
	int o1=0,o2=0,o3=0;
	if(l>0) o1=a1[l-1],o2=a2[l-1],o3=a3[l-1];
	if(a1[r]>o1 && a2[r]>o2 && a3[r]>o3) return 1;
	return 0;
}
int main(){
	cin>>t;
	f(q,0,t){
		int ans=N;
		cin>>s;
		n=s.size();
		a1[0]=(s[0]=='1');
		a2[0]=(s[0]=='2');
		a3[0]=(s[0]=='3');
		f(i,1,n){
			a1[i]=a1[i-1]+(s[i]=='1');
			a2[i]=a2[i-1]+(s[i]=='2');
			a3[i]=a3[i-1]+(s[i]=='3');
		}
		f(i,2,n){
			int l=-1,r=i,mid;
			while(l+1<r){
				mid=(l+r)/2;
				if(check(mid,i)) l=mid;
				else r=mid;
			}
			if(l>=0) minm(ans,i-l+1);
		}
		if(ans>n) cout<<0<<endl;
		else cout<<ans<<endl;
	}
}