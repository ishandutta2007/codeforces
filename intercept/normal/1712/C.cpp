#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int M=1e5+9;
int n;
int a[M],cnt[M],now[M],sum,ans;
void work(){
	sum=0;
	cin>>n;
	for(int i=1;i<=n;++i)cnt[i]=now[i]=0;
	for(int i=1;i<=n;++i){
		cin>>a[i],cnt[a[i]]++,now[a[i]]++;
		if(cnt[a[i]]==1)sum++;
	}
	ans=sum;
	int kt=0,mi=1e9;
	for(int i=n;i>=1;--i){
		if(a[i]>mi)break;
		now[a[i]]--;
		if(!kt)kt=a[i];
		else if(kt!=a[i])break;
		if(now[a[i]]==0)kt=0,ans--,mi=min(mi,a[i]);
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}