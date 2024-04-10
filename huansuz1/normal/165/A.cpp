#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<set>

#define ll long long
//#define mp make_pair
#define f first
#define s second

using namespace std;
int a[2160][2],b[2106][2],d,n,x[1234],y[1234],ans;


int main(){   
	cin>>n;
	for (int i=0; i<=2100; i++){
		a[i][1]=3000;
		b[i][1]=3000;
		a[i][0]=-3000;
		b[i][0]=-3000;
	}
	for (int i=0; i<n; i++) {
		cin>>x[i]>>y[i];
		x[i]+=1000;
		y[i]+=1000;
        a[x[i]][0]=max(a[x[i]][0],y[i]);
        a[x[i]][1]=min(a[x[i]][1],y[i]);
        b[y[i]][0]=max(b[y[i]][0],x[i]);
        b[y[i]][1]=min(b[y[i]][1],x[i]);
	}
	for (int i=0; i<n; i++) 
		if (a[x[i]][0]>y[i] && a[x[i]][1]<y[i] && b[y[i]][0]>x[i] && b[y[i]][1]<x[i]) ans++;

	cout<<ans;
		

	



	return 0;
}