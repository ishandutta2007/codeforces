#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1ll<<((x)-1))
int i,j,k,n,m,t;
char ch;
ll a[200500],r1,r2;
unordered_map<ll,int> mp,mp2;

int main(){
	mt19937_64 r(chrono::steady_clock::now().time_since_epoch().count()+1);
	long c=clock();
	scanf("%d%d%*d",&n,&m);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			ch=getchar();
			if(ch=='1'||ch=='0'){
				if(ch=='1'){a[i]|=b(j);}continue;
			}
			j--;
		}
	}
	while(clock()-c<=2600){
		int it=r()%n+1;mp.clear();mp2.clear();
		for(i=1;i<=n;i++){
			mp[a[i]&a[it]]++;
		}
		for(ll i=a[it];i;i=((i-1)&a[it])){
			k=mp[i];
			for(ll j=i;j;j=((j-1)&i)){
				mp2[j]+=k;
			}
			if(mp2[i]>=(n+1)/2){
				if(__builtin_popcountll(i)>r1){
					r1=__builtin_popcountll(i);r2=i;
				}
			}
		}
	}
	for(i=1;i<=m;i++){
		if(r2&b(i)){printf("1");}
		else{printf("0");}
	}
}