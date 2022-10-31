#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[200500],cnt,lst;
set<int> s;

int main(){
	cin>>n;
	cout<<n+1<<endl;
	printf("2 %d 1\n",n);
	printf("1 %d 114514\n",n);
	cnt=114514;
	for(i=1;i<n;i++){
		cnt--;
		printf("2 %d %d\n",i,cnt);
	}
}