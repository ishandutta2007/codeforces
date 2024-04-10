#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int i,j,k,n,m,t,a[500500],l[500500],res,lst,sb;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		res=0;
		memset(l,0,n*4+50);
		for(i=1;i<=n;i++){
			cin>>a[i];
			if(!l[a[i]]){
				l[a[i]]=i;res++;
			}
		}
		lst=n+1;
		for(i=n;i>=1;i--){
			//printf("NMSL%d %d\n",a[i],lst);
			if(a[i]>lst)break;
			for(j=l[a[i]];j<=i;j++){
				//printf("nmsl%d %d\n",j,i);
				if(a[j]!=a[i])goto aaa;
			}
			lst=a[i];
			i=l[a[i]];
			res--;
		}
		aaa:;
		cout<<res<<'\n';
	}
}