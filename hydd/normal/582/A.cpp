#include<cstdio>
#include<map>
#include<algorithm>
#include<functional>
using namespace std;
int n,a[310000];
int cnt,ans[310000];
map<int,int> mp;
int gcd(int a,int b){
	if (!b) return a;
	return gcd(b,a%b);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n*n;i++){
		scanf("%d",&a[i]);
		mp[a[i]]++;
	}
	sort(a+1,a+n*n+1,greater<int>());
	for (int i=1;i<=n*n;i++){
		if (!mp[a[i]]) continue;
		mp[a[i]]--;
		for (int j=1;j<=cnt;j++) mp[gcd(a[i],ans[j])]-=2;
		printf("%d ",a[i]); ans[++cnt]=a[i];
	}
	return 0;
}