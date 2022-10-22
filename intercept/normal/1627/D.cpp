#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int M=1e6+9;
int n;
int b[M];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int x;
		scanf("%d",&x);
		b[x]=1;
	}
	int ans=0;
	for(int i=1;i<M;++i){
		int x=0;
		for(int j=i;j<M;j+=i){
			if(b[j])x=__gcd(x,j);
		}
		if(x==i)ans++;
	}
	cout<<ans-n<<endl;
	return 0;
}
/*
1
3 5
-2 -7 -1
*/