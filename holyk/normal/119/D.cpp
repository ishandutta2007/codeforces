#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef unsigned long long ull;
const int N=1e6+5;
char a[N],b[N];
ull ha[N],hb[N],rb[N],cf[N];
int n,rp;
vector<int>g[N];
int main(){
	gets(a+1),gets(b+1);n=strlen(a+1);
	if(strlen(b+1)!=n)return puts("-1 -1");
	reverse(b+1,b+1+n);cf[0]=1;
//	cout<<b+1<<endl;
	REP(i,1,n)cf[i]=cf[i-1]*131,ha[i]=ha[i-1]*131+a[i],hb[i]=hb[i-1]*131+b[i];
	for(int i=n;i;--i)rb[i]=rb[i+1]*131+b[i];
	REP(i,1,n)if(b[i]==a[n]){
		int l=1,r=i;
		while(l<r){
			int mid=l+r+1>>1;
			if(hb[i]-hb[i-mid]*cf[mid]==ha[n]-ha[n-mid]*cf[mid])l=mid;else r=mid-1;
		}
		g[i-l].push_back(i);
	}
	for(int x:g[0])if(x>rp)rp=x;
	int ai=0,aj=0;
	REP(i,1,n)if(a[i]==b[i]){
		for(int x:g[i])if(x>rp)rp=x;
		if(rp<=i)continue;
		if(rb[rp+1]==ha[i+n-rp]-ha[i]*cf[n-rp])ai=i,aj=i+n-rp+1;					
	}else break;
	printf("%d %d",ai-1,aj-1);
	return 0;
}