#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
struct pq{
	std::multiset<int>a,b;
	int asum,bsum;
	pq(){
		asum=bsum=0;
	}
	void adjust(){
		int n=a.size()+b.size();
		while(a.size()>n/4){
			int x=*--a.end();
			bsum+=x,asum-=x;
			b.insert(x),a.erase(--a.end());
		}
		while(a.size()<n/4){
			int x=*b.begin();
			bsum-=x,asum+=x;
			a.insert(x),b.erase(b.begin());
		}
		if(!a.size())return;
		while(*a.rbegin()>*b.begin()){
			int x=*--a.end();
			bsum+=x,asum-=x;
			b.insert(x),a.erase(--a.end());
			x=*b.begin();
			bsum-=x,asum+=x;
			a.insert(x),b.erase(b.begin());
		}
	}
	void add(int x){
		asum+=x;
		a.insert(x);
		adjust();
	}
}
;
int n;
int main(){
	int T;
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		pq a,b;
		int x;
		for(int i=1;i<=n;i++)scanf("%d",&x),a.add(x);
		for(int i=1;i<=n;i++)scanf("%d",&x),b.add(x);
		int ans=0;
		while(a.bsum<b.bsum){
			ans++;
			a.add(100);
			b.add(0);
		}
		printf("%d\n",ans);
	}
}