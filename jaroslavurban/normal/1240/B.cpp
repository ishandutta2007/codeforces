#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int N=300100;
int a[N],l[N],r[N];
int n;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		cin>>n;
		for(int i=0;i<n;++i)cin>>a[i];
		for(int i=0;i<=n;++i)l[i]=-1;
		for(int i=0;i<n;r[a[i]]=i,++i)
			if(l[a[i]]==-1)l[a[i]]=i;
		int bst=1,cur=1,cnt=0,i=0;
		while(i<N&&l[i]==-1)++i;
		for(;i<=n;){
			int rg=i+1;
			while(rg<=n&&l[rg]==-1)++rg;
			if(rg>n)break;
			++cnt;
			if(r[i]<l[rg])++cur;
			else cur=1;
			bst=max(bst,cur);
			i=rg;
		}
		cout<<cnt+1-bst<<endl;
	}
}