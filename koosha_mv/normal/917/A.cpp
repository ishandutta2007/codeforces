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
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=5e5+99;

int n,t,a[N];

char s[5050];
int main(){
	scanf("%s",s);
	int i,j,l,r,n,ans=0;
	n=strlen(s);
	for (i=0; i<n; i++){
		l=0,r=0;
		for (j=i; j<n; j++){
			(s[j]=='(' ? l++ : l--);
			(s[j]==')' ? r-- : r++);
			if (l<0) l=1;
			if (r<0) break;
			if (l==0) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}