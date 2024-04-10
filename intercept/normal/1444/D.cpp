#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int M=1009;
int n[2],p[2],a[M];
vector<int>d[2];
bitset<500009>b[1009];
bool cmp(int l,int r){
	if(l<0||r<0)return l<r;
	return l>r;
} 
bool get(int o){
	int x=0;
	scanf("%d",&n[o]);
	p[o]=0;
	b[0]=1;
	for(int i=1;i<=n[o];++i)scanf("%d",&a[i]),b[i]=0;	
	sort(a+1,a+n[o]+1);
	d[o].clear();
	for(int i=1;i<=n[o];++i){
		b[i]=b[i-1]|(b[i-1]<<a[i]);
		x+=a[i];
	}
	if(x%2==0&&b[n[o]][x/2]){
		x/=2;
		for(int i=n[o];i>=1;--i){
			if(x>=a[i]&&b[i-1][x-a[i]])d[o].eb(a[i]),x-=a[i],p[o]++;
			else d[o].eb(-a[i]);
		}
		if(p[o]<n[o]-p[o])for(auto&y:d[o])y=-y;
		sort(d[o].begin(),d[o].end(),cmp);
		return 1;
	}
	return 0;
}

void work(){
	bool bol=(!get(0))|(!get(1))|(n[0]!=n[1]);
	if(bol)printf("No\n");
	else {
		reverse(d[1].begin(),d[1].end());
		int x=0,y=0;
		printf("Yes\n");
		for(int i=0;i<n[0];++i){
			x+=d[0][i];
			printf("%d %d\n",x,y);
			y+=d[1][i];
			printf("%d %d\n",x,y);
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}