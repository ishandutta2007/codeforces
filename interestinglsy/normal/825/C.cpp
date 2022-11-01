#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#define pb push_back
#define mp make_pair
#define INF 9999999999
#define LINF 9999999999999999
#define SINF "%"
#define uint unsigned int
#define msn(a,v) memset(a,v,sizeof(a))
#define ms(a) msn(a,0)
#define NONE -1
#define ll long long
#define ull unsigned ll
#define uchar unsigned char
#define sint short int
#define usint unsigned sint
#define xsize(a) sizeof(a)/1024/1024
#define fr(aaaaa,bbbbb) for(aaaaa = 1;aaaaa <= bbbbb;aaaaa++)
#define frr(aaaaa,bbbbb,ccccc) for(aaaaa = ccccc;aaaaa <= bbbbb;aaaaa++)
using namespace std;

#define MAXN 2010
ll n,k;
ll maxk = -1;
ll a[MAXN];

int main(){
//	freopen("C.txt","r",stdin);
	scanf("%I64d %I64d",&n,&k);
	for(ll i = 1;i <= n;i++){
		scanf("%I64d",&a[i]);
		maxk = max(maxk,a[i]);
	}
	
	ll ans = 0;
	if(maxk > k * 2){
		ll nowk = k;
		for(int j = 1;j <= n;j++)
			for(int i = 1;i <= n;i++)
				if(a[i] <= nowk * 2  &&  a[i] > nowk)
					nowk = a[i];
		while(maxk > nowk * 2){
			nowk *= 2;
			ans++;
			for(int j = 1;j <= n;j++)
			for(int i = 1;i <= n;i++)
				if(a[i] <= nowk * 2  &&  a[i] > nowk)
					nowk = a[i];
		}
	}
	
	printf("%I64d\n",ans);
	
	return 0;
}