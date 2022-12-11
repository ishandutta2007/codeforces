#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
ull C[100][100];
int main(){
	{
		int n=99;
		for (int i=0;i<=n;++i){
			C[i][0]=C[i][i]=1;
			for (int j=1;j<i;++j)
				C[i][j]=C[i-1][j-1]+C[i-1][j];
		}
	}
	int T; scanf("%d",&T);
	vector<int> rem;
	while (T--){
		long long x; scanf("%lld",&x);
		
		static int cnt[30];
		memset(cnt,0,sizeof(cnt));
		
		int n=0;
		for (int i=2;x;++i)
			cnt[x%i]++,x/=i,++n;
		int N=n;
		ull ans=1;
		
		for (int i=29;i>=0;--i) if (cnt[i])
			ans*=C[n-max(i,1)+1][cnt[i]],n-=cnt[i];
		
		
		if (cnt[0]){
			ull t=1; n=N;
			--cnt[0]; --n;
			for (int i=29;i>=0;--i) if (cnt[i])
				t*=C[n-max(i,1)+1][cnt[i]],n-=cnt[i];
			ans-=t;
		}
		
		printf("%llu\n",ans-1);
		
	}
}