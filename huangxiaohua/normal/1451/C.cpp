#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

int i,j,k,n,t,a[30],b[30];
char sb1[1005000],sb2[1005000];

int main(){
	cin>>t;
	while(t--){
		cin>>n>>k;
		cin>>sb1+1>>sb2+1;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(i=1;i<=n;i++){
			a[sb1[i]-'a'+1]++;
		}
		for(i=1;i<=n;i++){
			b[sb2[i]-'a'+1]++;
		}
		for(i=1;i<=26;i++){
			
			if(a[i]>=b[i]&&((a[i]-b[i])%k)==0){a[i+1]+=(a[i]-b[i]);a[i]-=(a[i]-b[i]);}
			else{puts("NO");goto aaa;}
			//printf("%d %d\n",a[i],b[i]);
			
		}
		puts("YES");
		aaa:;
	}
}