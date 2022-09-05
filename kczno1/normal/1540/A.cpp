#include<bits/stdc++.h>
using namespace std;

typedef long long s64;

int main(){
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int tt;
	cin>>tt;
	while(tt--){
		int n;
		scanf("%d",&n);
		vector<int> d(n);
		for(auto &x:d)scanf("%d",&x);
		sort(d.begin(),d.end());
		s64 sum=0;
		for(int i=0;i<n;++i)sum+=d[i]*s64(n-1-2*i);
		cout<<sum+d.back()<<endl;
	}
}