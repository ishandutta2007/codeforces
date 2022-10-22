#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxx = 200005; 
int a[maxx];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		int minn = 2e7;
		map<int , int> mp;
		for(int i=1;i<=n;i++)
		{
			if(mp[a[i]]){
				minn = min(minn , i - mp[a[i]] + 1);
				mp[a[i]] = i;
			}else{
				mp[a[i]] = i;
			}
		}
		if(minn == 2e7){
			printf("-1\n");
		}
		else{
			printf("%d\n",minn);
		}
	}
	return 0;
 }