#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
int a,b,c,t1,t2,t3;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&a,&b,&c);
		t1=t2=t3=0;
		t1=(a-1)+a*(b-1);
		if(t1==c){
			puts("YES");
		}
		else{
			puts("NO");
		}

	}
}