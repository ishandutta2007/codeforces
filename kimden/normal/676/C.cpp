#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;
	int a[100010],b[100010];
	int am=0,bm=0;
	a[am++]=-1;
	b[bm++]=-1;
	char c;
	for(int i=0;i<n;i++){
		c='\n';
		while(c=='\n'){
			cin >> c;
		}
		if(c=='a'){
			a[am++]=i;
		}else{
			b[bm++]=i;
		}
	}
	a[am++]=n;
	b[bm++]=n;
	int ans=0;
	for(int i=0;i<max(1,am-k-1);i++){
		ans = max(ans,a[min(am-1,i+k+1)]-a[i]);
	}
	for(int i=0;i<max(1,bm-k-1);i++){
		ans = max(ans,b[min(bm-1,i+k+1)]-b[i]);
	}
	ans--;
	cout << ans;
	return 0;
}