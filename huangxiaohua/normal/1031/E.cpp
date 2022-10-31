#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))

int i,j,k,n,m,t,it,a[105],sb,x,y,z;
bitset<100050> b;
tuple<int,int,int> op[105];
vector< tuple<int,int,int> >res;

void solve0(){
	it=0;
	for(i=2;i<n;i++){
		for(j=1;i-j>=1&&i+j<=n;j++){
			a[++it]=b(i);
			a[it]|=b(i-j);
			a[it]|=b(i+j);
			op[it]={i-j,i,i+j};
		}
	}
	for(i=1;i<=n;i++){
		if(b[i])sb|=b(i);
	}
	for(t=0;t<b(it+1);t++){
		k=0;
		for(i=1;i<=it;i++){
			if(t&b(i)){
				k^=a[i];
			}
		}
		if(k==sb){
			printf("YES\n%d\n",__builtin_popcount(t));
			for(i=1;i<=it;i++){
				if(t&b(i)){
					auto [x,y,z]=op[i];
					printf("%d %d %d\n",x,y,z);
				}
			}
			exit(0);
		}
	}
	puts("NO");
}

void work(int l,int r){
	int i,j,k,t,sb2;
	it=0;
	for(i=2;i<=11;i++){
		for(j=1;i-j>=1&&i+j<=11;j++){
			a[++it]=b(i);
			a[it]|=b(i-j);
			a[it]|=b(i+j);
			op[it]={i-j+l-1,i+l-1,i+j+l-1};
		}
	}
	sb=0;
	for(i=l;i<=r;i++){
		if(b[i]){
			sb|=b(i-l+1);
		}
	}
	for(i=0;i<=it;i++){
		for(j=0;j<=it;j++){
			sb2=(sb^a[i]^a[j]);
			for(k=11;k>=6;k--){
				if(sb2&b(k))goto aaa;
			}
			if(i){
				res.push_back(op[i]);
			}
			if(j){
				res.push_back(op[j]);
			}
			for(i=11;i>=1;i--){
				if(sb2&b(i)){
					b[i+l-1]=1;
				}
				else b[i+l-1]=0;
			}
			return;
			aaa:;
		}
	}
}

void solve1(){
	it=0;
	for(i=2;i<11;i++){
		for(j=1;i-j>=1&&i+j<=11;j++){
			a[++it]=b(i);
			a[it]|=b(i-j);
			a[it]|=b(i+j);
			op[it]={i-j,i,i+j};
		}
	}
	sb=0;
	for(i=1;i<=11;i++){
		if(b[i])sb|=b(i);
	}
	for(t=0;t<b(it+1);t++){
		k=0;
		for(i=1;i<=it;i++){
			if(t&b(i)){
				k^=a[i];
			}
		}
		if(k==sb){
			for(i=1;i<=it;i++){
				if(t&b(i)){
					res.push_back(op[i]);
				}
			}
			return;
		}
	}
}

int main(){
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()+1);
	uniform_int_distribution<int>lim(1,100);
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		b[i]=k;
	}
	if(n<=11){
		solve0();
		return 0;
	}
	for(i=n;i-10>=1;i-=6){
		work(i-10,i);
	}
	//cout<<b<<endl;
	solve1();
	puts("YES");
	cout<<res.size()<<endl;
	for(auto [x,y,z]:res){
		printf("%d %d %d\n",x,y,z);
	}
}