#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int i,j,t,n,a,b,c,d,e,f,r1,r2;
 
int main(){
	scanf("%d",&n);
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	r1=max(a-f-d,b-d-e);
	r1=max(r1,c-e-f);
	r2=min(a,e)+min(b,f)+min(c,d);
	printf("%d %d\n",max(r1,0),r2);
}