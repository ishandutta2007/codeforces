#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

int add(int i,int j){
	int x,y;
	cout<<"or "<<i+1<<" "<<j+1<<endl;
	cin>>x;
	cout<<"and "<<i+1<<" "<<j+1<<endl;
	cin>>y;
	return 2*y+(x^y);
}

void ProGamerMove(){
	int n,k;cin>>n>>k;
	vector<int>a(n);
	int x=add(0,1),y=add(0,2),z=add(1,2);
	a[2]=(y+z-x)/2;
	a[0]=y-a[2];
	a[1]=x-a[0];
	for(int i=3;i<n;++i)a[i]=add(0,i)-a[0];
	sort(a.begin(),a.end());
	cout<<"finish "<<a[k-1]<<endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout<<setprecision(9)<<fixed;
	int tc=1;
//	cin>>tc;
	while(tc--)ProGamerMove();
}