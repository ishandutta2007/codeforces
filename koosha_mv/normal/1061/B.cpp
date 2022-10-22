#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

ll s,x;

int main(){
	int n , m ;
	cin >> n >> m ;
	int a[n] ;
	for(int i = 0 ; i < n ; ++i) cin >> a[i] , s+=a[i] ;
	sort(a,a+n) ;
	for(int i = 0 ; i < n ; ++i) if(a[i]>x) x++ ;
	cout << s-(n+a[n-1]-x) ;
}