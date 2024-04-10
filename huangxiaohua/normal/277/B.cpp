#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,sb;
int main(){
	cin>>n>>m;
	if(m==3&&n>4)return puts("-1"),0;
	for(i=1;i<=m;i++){
		sb+=114*i;
		printf("%d %d\n",1919+i,sb);
	}
	if(n>m){
		printf("%d %d\n",198964+m+1,sb);
		for(i=m+2;i<=n;i++){
			sb-=114*(m+m+2-i);
			printf("%d %d\n",198964+i,sb);
		}
	}
}