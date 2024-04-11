#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
int n,a[maxn];
int ans[maxn],tot;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int now=0,l=1,r=n;
	while(1){
		if(now<a[l] && now<a[r] && a[l]!=a[r]){
			if(a[l]<a[r])now=a[l],l++,ans[++tot]=0;
			else now=a[r],r--,ans[++tot]=1;
		}
		else if(now<a[l] && now>=a[r]){
			now=a[l],l++,ans[++tot]=0;
		}
		else if(now>=a[l] && now<a[r]){
			now=a[r],r--,ans[++tot]=1;
		}
		else if(now<a[l] && now<a[r] && a[l]==a[r]){
			int tmp1=1,tmp2=1,ll=l,rr=r;
			while(a[ll]<a[ll+1])ll++,tmp1++;
			while(a[rr]<a[rr-1])rr--,tmp2++;
			if(tmp1>tmp2){
				while(tmp1--)ans[++tot]=0;
			}
			else {
				while(tmp2--)ans[++tot]=1;
			}
			break;
		}
		else break;
	}
	cout<<tot<<endl;
	for(int i=1;i<=tot;i++)
		if(!ans[i])cout<<'L';
		else cout<<'R'; 
	}