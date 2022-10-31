#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

int i,j,k,n,m,a[100500],it;
set<int> s[100500];
ll res;
void add(int x,int y){
	for(int i=x;i<=n;i+=(-i&i)){a[i]+=y;}
}

int get(int x,int y=0){
	for(;x;x-=(-x&x)){y+=a[x];}return y;
}

int main(){
	scanf("%d",&n);it=n;
	for(i=1;i<=100000;i++){s[i].insert(0);s[i].insert(11451419);}
	for(i=1;i<=n;i++){
		add(i,1);
		scanf("%d",&k);s[k].insert(n+1-i);
	}
	auto sb=s[1].upper_bound(0);
	for(i=1;i<=100000;i++){
		while(s[i].size()>2){
			sb=s[i].upper_bound(it);sb--;
			//printf("a%d %d %d %d\n",it,*sb,res,get(it));
			if(!(*sb)){res+=get(n);sb=s[i].find(11451419);sb--;}
			res+=get(it)-get(*sb)+1;
			it=*sb;
			add(it,-1);
			s[i].erase(sb);
		}
	}
	printf("%lld",res);
}