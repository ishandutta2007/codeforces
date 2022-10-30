#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,a[105],b[105],mx;
string s;
map<string,int> mp;
#define cnt(x) __builtin_popcount(x)

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){scanf("%d",&a[i]);}
	for(i=0;i<=32767;i++){
		s.clear();mx=0;
		for(j=1;j<=n;j++){b[j]=cnt((a[j]&32767)^i);mx=max(mx,b[j]);}
		for(j=1;j<=n;j++){s+=mx-b[j]+'0';}
		mp[s]=i+1;
	}
	for(i=0;i<=32767;i++){
		s.clear();mx=1145141919;
		for(j=1;j<=n;j++){b[j]=cnt((a[j]>>15)^i);mx=min(mx,b[j]);}
		for(j=1;j<=n;j++){s+=b[j]-mx+'0';}
		if(mp[s]){printf("%d",mp[s]-1+(i<<15));return 0;}
	}
	puts("-1");
}