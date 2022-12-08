#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n,k;
int a[N];

void Main()
{
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		int s;scanf("%d",&s);
		if(s>k)a[i]=2;
		else if(s==k)a[i]=1;
		else a[i]=0;
	}
	if(n==1){
		if(a[1]==1)puts("yes");
		else puts("no");
		return ;
	}
	int r1=0,r2=0;
	for(int i=1;i<=n;i++){
		for(int j=max(1,i-2);j<=min(n,i+2);j++){
			if(a[i]&&a[j]&&i!=j){
				r1=1;
			}
		}
	}
	for(int i=1;i<=n;i++)if(a[i]==1)r2=1;
	if(r1&&r2)puts("yes");
	else puts("no");
}

int main()
{
	int T;cin >> T;
	while(T--){
		Main();
	}
}