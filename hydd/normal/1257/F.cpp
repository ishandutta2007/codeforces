#include<bits/stdc++.h>
using namespace std;
const int upperlim=(1<<15)-1;
int n,a[110];
map<vector<int>,int> mp; 
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=0;i<=upperlim;i++){
		int tmp=__builtin_popcount((a[1]&upperlim)^i);
		vector<int> v;
		for (int j=2;j<=n;j++)
			v.push_back(tmp-__builtin_popcount((a[j]&upperlim)^i));
		mp[v]=i;
	}
	for (int i=0;i<=upperlim;i++){
		int tmp=__builtin_popcount((a[1]>>15)^i);
		vector<int> v;
		for (int j=2;j<=n;j++) v.push_back(__builtin_popcount((a[j]>>15)^i)-tmp);
		if (mp.count(v)){
			printf("%d\n",(i<<15)+mp[v]);
			return 0;
		}
	}
	puts("-1");
	return 0;
}