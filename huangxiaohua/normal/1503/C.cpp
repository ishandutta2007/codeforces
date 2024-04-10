#include <bits/stdc++.h>
using namespace std;
int i,j,k,n,r;
long long res;
vector<vector<int> >v;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){scanf("%d%d",&j,&k);res+=k;v.push_back({j,j+k});}
	sort(v.begin(),v.end());
	r=v[0][1];
	for(i=0;i<n;i++){res+=max(0,v[i][0]-r);r=max(r,v[i][1]);}
	printf("%lld",res);
}