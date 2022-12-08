#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int cnt[N], n;
int v[N];

int main()
{
	cin >> n;
	for(int i=1;i<=n;++i){
		int num;
		scanf("%d",&num);
		cnt[num]++;
	}
	for(int i=1;i<=200000;i++){
		for(int j=i*2;j<=200000;j+=i)cnt[i]+=cnt[j],v[j]=i>1;
	}
	long long ans=1;
	for(int i=2;i<=200000;i++)if(!v[i]){
		for(long long j=i;j<=200000;j=j*i){
			// if(cnt[j])cout << j << ":" << cnt[j] << endl;
			if(cnt[j]>=n-1){
				ans=ans*i;
			}
		}
	}
	cout << ans << endl;
}