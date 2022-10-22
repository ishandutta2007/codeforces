#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define LL long long
using namespace std;
const int N=2e5+10;
int n;
int a[N];
LL x,y;
LL ans1=0,ans2=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	//for(int i=1;i<=n;++i) cout<<a[i]<<endl;
	if(a[1]>0) {ans2++;++x;}
	else {
		ans1++;++y;
	}
	for(int i=2;i<=n;++i){
		if(a[i]>0){
			ans2+=x;
			ans1+=y;
			++ans2;
			++x;
		}
		else{
			ans1+=x;
			ans2+=y;
			++ans1;
			swap(x,y);
			++y;
		}
		//cout<<ans1<<" "<<ans2<<endl;
	}
	cout<<ans1<<" "<<ans2<<endl;
}