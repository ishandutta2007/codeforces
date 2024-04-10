#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
int a[109];
void work(){
	int n;
	cin>>n;
	cout<<n<<endl;
	for(int i=1;i<=n;++i)a[i]=i;
	for(int i=1;i<=n;++i){
		swap(a[i],a[1]);
		for(int j=1;j<=n;++j)cout<<a[j]<<" ";
		puts("");
	}
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}