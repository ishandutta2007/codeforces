#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e5+5,M=2e5+5,mo=1e9+7;
int n,k,t;
int a[N],cnt,cnt0,cnt1;
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	for(;t--;){
		cin>>n>>k;
		fo(i,1,n)cin>>a[i];
		cnt=cnt0=cnt1=0;
		fo(i,1,n){
			cnt+=a[i]==k;
			cnt0+=i+1<=n&&a[i]>=k&&a[i+1]>=k;
			cnt1+=i+2<=n&&a[i]>=k&&a[i+2]>=k;
		}
		if(cnt&&(cnt0+cnt1||n==1))printf("yes\n");else printf("no\n");
	}
}