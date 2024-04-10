#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int A[210000],n;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	sort(A+1,A+n+1); int num=(n-2)/2,ans=2e9;
	for (int i=0;i<=num;i++){
		int l=A[num-i+1],r=A[n-i]; ans=min(ans,r-l);
	}
	cout<<ans<<endl; return 0;
}