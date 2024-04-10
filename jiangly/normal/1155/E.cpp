#include<bits/stdc++.h>
typedef std::vector<int> poly;
const int K=12,P=1e6+3;
int Pow(int a,int b){
	int ans=1;
	while(b){
		if(b&1){
			ans=1ll*ans*a%P;
		}
		a=1ll*a*a%P;
		b>>=1;
	}
	return ans;
}
poly get_poly_by_points(const std::vector<std::pair<int,int>>&p){
	int n=p.size();
	poly L(n);
	poly l(n+1);
	l[0]=1;
	for(int i=0;i<n;++i){
		for(int j=i;j>=0;--j){
			l[j+1]=(l[j+1]+l[j])%P;
			l[j]=(-1ll*p[i].first*l[j]%P+P)%P;
		}
	}
	for(int i=0;i<n;++i){
		poly a(n+1);
		int w=0;
		for(int j=n-1;j>=0;--j){
			a[j]=(l[j+1]+1ll*p[i].first*a[j+1])%P;
			w=(1ll*w*p[i].first+a[j])%P;
		}
		w=Pow(w,P-2);
		for(int j=0;j<n;++j){
			L[j]=(L[j]+1ll*a[j]*p[i].second%P*w)%P;
		}
	}
	return L;
}
int main(){
	std::vector<std::pair<int,int>>p;
	for(int i=0;i<=10;++i){
		printf("? %d\n",i);
		fflush(stdout);
		int y;
		scanf("%d",&y);
		p.push_back({i,y});
	}
	poly f=get_poly_by_points(p);
	for(int i=0;i<P;++i){
		int ans=0;
		for(int j=10;j>=0;--j){
			ans=(1ll*ans*i+f[j])%P;
		}
		if(!ans){
			printf("! %d\n",i);
			fflush(stdout);
			return 0;
		}
	}
	puts("! -1");
	fflush(stdout);
	return 0;
}