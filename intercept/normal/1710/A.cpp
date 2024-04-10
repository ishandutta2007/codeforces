#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int M=1e5+9;
int n,m,k;
int a[M];
void work(){
	cin>>n>>m>>k;
	for(int i=1;i<=k;++i){
		cin>>a[i];
	}
	ll l=0,r=0;
	bool fl=0,fr=0;
	for(int i=1;i<=k;++i){
		if(a[i]/n>1)l+=a[i]/n,fl|=a[i]/n>2;
		if(a[i]/m>1)r+=a[i]/m,fr|=a[i]/m>2;
	}
	if(l>=m&&((m%2==1&&fl)||m%2==0))puts("Yes");
	else if(r>=n&&((n%2==1&&fr)||n%2==0))puts("Yes");
	else puts("No");
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
5 2
2 2 2 4 5
2 3
5 3
*/