#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<set>
#include<map>
#include<string>
#include<cstring>
#include<queue>
#include<cstdio>
#include<vector>
#define f first 
#define s second 
#define mp make_pair 
#define ll long long
#define pii pair<int,int>

using namespace std;

ll a[1234561], t[4321123],t1[4123123],d[1234123],ans;
int n,z,z1;
map< ll, int > b;
void upd(int v, int tl, int tr, int pos){
	if (tl==tr) { 
		t[v]=1;
	} else {
		int tm=(tl+tr)/2;
		if (pos<=tm) upd(v*2,tl,tm,pos); else 
			upd(v*2+1,tm+1, tr,pos);
		t[v]=t[v*2]+t[v*2+1];	
	}
}


int sum(int v, int tl, int tr, int x , int y){
	if (tl>y || tr<x) return 0;
	if (tl>=x && tr<=y) return t[v];
	int tm=(tl+tr)/2;
	return sum(v*2,tl,tm,x,y)+sum(v*2+1,tm+1,tr,x,y);

}

int main(){
	scanf("%d",&n);
	for (int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		d[i]=a[i];
		b[a[i]]=i;
	}
	sort(d+1, d+n+1);
	for (int i=1; i<=n; i++)
		a[i]=b[d[i]];
			
	for (int i=1; i<=n; i++) {
		upd(1,1,n,a[i]);
		int s=sum(1,1,n,a[i]+1,n);		
		ll w=(a[i]-abs(i-s));
		if (w<0) w=0;
		ans+=(s*w);
	}
	cout<<ans;




}