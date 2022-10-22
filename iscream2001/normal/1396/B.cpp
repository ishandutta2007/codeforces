#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define LL long long
using namespace std;
const int N=2e5+10;
const int inf=1e9+10;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int n;
int a[N];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int sum=0,mx=0;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			sum+=a[i];
			mx=max(mx,a[i]);
		}
		if(n==1){
			cout<<"T"<<endl;
		}
		else if(n==2){
			if(a[1]==a[2]) cout<<"HL"<<endl;
			else cout<<"T"<<endl;
		}
		else {
			if(mx>(sum/2)) cout<<"T"<<endl;
			else if(sum%2==1) cout<<"T"<<endl;
			else cout<<"HL"<<endl;
		}
	} 
	return 0;
}
/*

2
3 3
-1 2 3
3 1
-1 2 3
*/