#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int N=100100;
int a[N];
int n;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	int aa=-1,bb=-1,af=0,bf=0,mnb=0;
	int res=0;
	for(int i=0;i<n;++i){
		res=max(res,i-mnb);
		if(a[i]==aa){
			bf=i+1;continue;
		}
		if(aa==-1){
			aa=a[i];bf=1;continue;
		}
		if(a[i]==bb){
			af=i+1;continue;
		}
		if(bb==-1){
			bb=a[i];af=i+1;bf=i;continue;
		}
		if(abs(a[i]-aa)==1){
			mnb=af;af=i+1;
			bb=a[i];bf=i;continue;
		}
		if(abs(a[i]-bb)==1){
			mnb=bf;bf=i+1;
			aa=a[i];af=i;continue;
		}
	}
	res=max(res,n-mnb);
	cout<<res<<endl;
}