#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=45;
int i,j,k,n,m,a[maxn],Num[2],need;
int main(){
	int T;
	cin>>T;
	while(T--){
		Num[0]=Num[1]=need=0;
		cin>>n;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			Num[a[i]&1]++;
			if((a[i]&1) && (i&1)==0)++need;
		}
		if(Num[0]!=(n+1)/2)puts("-1");
		else printf("%d\n",need);
	}
	return 0;
}