#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int n,m,ans,pd[310000],now,k;
struct atom{
	vector<int>A;
	int l;
	void push(int t){
		A.push_back(t);
	}
	void read(int t){
		while (l<A.size()&&A[l]<=t) l++;
	}
	void readall(){
		for (int i=l;i<A.size();i++)
			if (pd[A[i]]==0) ans--,pd[A[i]]=1;
		l=A.size();
	}
}x[310000];
int main(){
	scanf("%d%d",&n,&m); k=0;
	for (;m;m--){
		int k1,k2; scanf("%d%d",&k1,&k2);
		if (k1==1){
			x[k2].push(++k); ans++;
		} else if (k1==2){
			x[k2].readall();
		}else {
			for (int i=now+1;i<=k2;i++)
				if (pd[i]==0){
					ans--; pd[i]=1;
				}
			now=max(now,k2);
		}
		printf("%d\n",ans);
	}
}