#include <bits/stdc++.h>
using namespace std;
#define N 500500
int i,j,k,n,m,t,f[N],a[N],b[N],c[N],op[N];
#define add(x) f[a[k]]-=x;f[b[k]]+=x;f[c[k]]+=x;
int main(){
	cin>>n;
	for(i=1;i<=n*4;i++){cin>>a[i]>>b[i]>>c[i];op[i]=i;f[i]=4;}
	puts("YES");
	for(i=n*4;i>=1;i--){
		while(1){
			j=rand()%i+1;k=op[j];add(1);
			if(f[b[k]]>9||f[c[k]]>9){add(-1);}
			else{cout<<k<<' ';swap(op[j],op[i]);break;}
		}
	}
}