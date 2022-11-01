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
#define INF 9999999
#define LINF 9999999999999999
#define SINF "%"
#define uint unsigned int
#define msn(a,v) memset(a,v,sizeof(a))
#define ms(a) msn(a,0)
#define NONE -1
#define allowxout 1
#define ll long long
#define ull unsigned ll
#define uchar unsigned char
#define xout(a) if(allowxout) cout << "[X] " << a << " "
#define xout2(a,b) if(allowxout) cout << "[X2] " << a << " " << b << " "
#define xoutln(a) if(allowxout) cout << "[X] " << a << endl
#define xout2ln(a,b) if(allowxout) cout << "[X2] " << a << " " << b << endl
using namespace std;

int n,k;
int a[200001];
int b[200001];

class Dis{
public:
	int aa;	//before
	int bb;	//after
	int disc;	// 
};
Dis dis[200001];
Dis makedis(int aa,int bb){
	Dis d;
	d.aa = aa;
	d.bb = bb;
	d.disc = aa-bb;
	return d;
}
bool operator<(Dis d1,Dis d2){
	return d1.disc < d2.disc;
}

int main(){
//	freopen("C.txt","r",stdin);
	
	while(scanf("%d %d",&n,&k) != EOF){
		for(int i = 1;i <= n;i++)
			scanf("%d",&a[i]);
		for(int i = 1;i <= n;i++)
			scanf("%d",&b[i]);
		
		for(int i = 1;i <= n;i++)
			dis[i] = makedis(a[i],b[i]);
		sort(dis+1,dis+n+1);
		
		ll ans = 0;
		for(int i = 1;i <= k;i++)
			ans += dis[i].aa;
		int i = k+1;
		while(dis[i].disc < 0){
			ans += dis[i].aa;
			i++;
		}
		for(;i <= n;i++)
			ans += dis[i].bb;
		
		printf("%I64d\n",ans);
	}
	return 0;
}