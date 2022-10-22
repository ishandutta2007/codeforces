#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
const int N=4e5+9;
int n,t,a[N],b[N],gh,g,ans;
int main(){
	get(t);
	f(q,0,t){
		get(n);
		gh=0,g=0;
		ans=1;
		f(i,0,n){
			get(a[i]);b[i]=a[i];
			if(g==0){
				if(i>0 && a[i]<=a[i-1]){
					g=1;
					if(a[i]<=0 && a[i]==b[i-1]) ans=0;
					else
						gh=min(b[i-1]-1,a[i]);
				}
				else{
					if(i==0)
						a[i]=min(a[i],0);
					else
						a[i]=max(a[i-1]+1,0);
				}
			}
			else{;
				if(gh<=0)
					ans=0;
				else{
					gh=min(gh-1,a[i]);
				}
			}
		}
		if(ans==0)
			cout<<"NO";
		else
			cout<<"YES";
		cout<<endl;
	}
}