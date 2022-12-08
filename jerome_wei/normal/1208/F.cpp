#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> dat;
pair<int,int> f[1<<21];

dat merge(dat a,dat b){
	int f[4]={a.first,a.second,b.first,b.second};
	sort(f,f+4);
	return dat(f[3],f[2]);
}
int n,a[1<<20];


int main()
{
	cin >> n;
	for(int i=0;i<1<<21;i++)f[i]=dat(0,0);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		f[a[i]]=merge(f[a[i]], dat(i,0));
	}
	for(int i=0;i<21;i++){
		for(int j=0;j<1<<21;j++)if(1&(j>>i)){
			f[j-(1<<i)]=merge(f[j-(1<<i)], f[j]);
		}
	}
	int ans=0;
	for(int i=1;i<=n-2;i++){
		int cur=0;
		for(int j=20;~j;j--)if(!(1&(a[i]>>j))){
			if(f[cur|(1<<j)].second > i){
				cur|=1<<j;
				// cout << cur << " " << f[cur].second << endl;
			}
		}
		ans=max(ans, cur|a[i]);
	}
	cout << ans << endl;
}