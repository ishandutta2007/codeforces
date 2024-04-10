#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+10;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
char get(){
	char ch=getchar();
	while(ch<'a'||ch>'z') ch=getchar();
	return ch;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int R,G,B;
int a[210],b[210],c[210];
bool cmp(int x,int y){
	return x>y;
}
int f[210][210][210];
void umx(int &x,int y){
	if(x<y) x=y;
}
int main(){
	cin>>R>>G>>B;
	for(int i=1;i<=R;++i) cin>>a[i];
	for(int i=1;i<=G;++i) cin>>b[i];
	for(int i=1;i<=B;++i) cin>>c[i];
	sort(a+1,a+1+R,cmp);
	sort(b+1,b+1+G,cmp);
	sort(c+1,c+1+B,cmp);
	
	int ans=0;
	for(int i=0;i<=R;++i){
		for(int j=0;j<=G;++j){
			for(int k=0;k<=B;++k){
				umx(ans,f[i][j][k]);
				if(i<R&&j<G) umx(f[i+1][j+1][k],f[i][j][k]+a[i+1]*b[j+1]);
				if(i<R&&k<B) umx(f[i+1][j][k+1],f[i][j][k]+a[i+1]*c[k+1]);
				if(j<G&&k<B) umx(f[i][j+1][k+1],f[i][j][k]+b[j+1]*c[k+1]);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}