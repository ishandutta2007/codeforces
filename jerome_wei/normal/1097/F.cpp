#include<bits/stdc++.h>
using namespace std;
const int N=7003;
bitset<N> t[100010],st[N];
bitset<N> mu[N];
int n,m;
int mu_[N];
int main()
{
	mu_[1] = 1;
	for (int i = 1; i <= 7000; i++)
		for (int j = i + i; j <= 7000; j += i)
			mu_[j] -= mu_[i];
	for (int i = 1; i <= 7000; i++)
		for (int j = i; j <= 7000; j += i)
			st[j][i] = 1;
	for (int i = 1; i <= 7000; i++)
		for (int j = i; j <= 7000; j += i)
			if(mu_[j / i]) mu[i][j] = 1;
	cin >> n >> m;
	while(m--){
		int opt;scanf("%d",&opt);
		if(opt==1){
			int x,v;scanf("%d%d",&x,&v);
			t[x]=st[v];
		}else if(opt==2){
			int x,y,z;scanf("%d%d%d",&x,&y,&z);
			t[x]=t[z] ^ t[y];
		}else if(opt==3){
			int x,y,z;scanf("%d%d%d",&x,&y,&z);
			t[x]=t[y] & t[z];
		}else{
			int x,v;scanf("%d%d",&x,&v);
			printf("%d", (t[x] & mu[v] ).count() %2);
		}
	}
}