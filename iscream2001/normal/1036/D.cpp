#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<set>
#include<queue>
#include<bitset>
#include<vector>
#define LL long long
using namespace std;
const int N=3e5+10;
int n,m;
LL a[N],b[N],A=0,B=0; 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%I64d",&a[i]),A+=a[i];
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
		scanf("%I64d",&b[i]),B+=b[i];
	if(A!=B){
		cout<<-1<<endl;
		return 0;
	}
	int i=0,j=0,ans=0;
	while(i<n&&j<m){
		++i;++j;
		A=a[i];B=b[j];
		while(A!=B){
			if(A<B){
				++i;A+=a[i];
			}
			else{
				++j;B+=b[j];
			}
		}
		++ans;
	}
	cout<<ans<<endl;
}