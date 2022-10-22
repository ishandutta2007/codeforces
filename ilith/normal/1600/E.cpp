#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=2e5+5;
int n,a[maxn],s1[maxn],s2[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	s1[1]=1;
	for(int i=2;i<=n;i++) s1[i]=a[i]<a[i-1]?s1[i-1]+1:1;
	s2[n]=1;
	for(int i=n-1;i>0;i--) s2[i]=a[i]<a[i+1]?s2[i+1]+1:1;
	int l=1,r=n,lst=-1;
	while(1)
		if(a[l]<=lst&&a[r]<=lst){
			printf((n-r+l)%2==1?"Bob\n":"Alice\n");
			return 0;
		}
		else if(a[l]>a[r]){
			if(s2[l]%2==1){
				printf((n-r+l)%2==1?"Alice\n":"Bob\n");
				return 0;
			}
			else if(a[r]<=lst){
				printf((n-r+l)%2==1?"Bob\n":"Alice\n");
				return 0;
			}
			else lst=a[r--];
		}
		else if(a[l]<a[r]){
			if(s1[r]%2==1){
				printf((n-r+l)%2==1?"Alice\n":"Bob\n");
				return 0;
			}
			else if(a[l]<=lst){
				printf((n-r+l)%2==1?"Bob\n":"Alice\n");
				return 0;
			}
			else lst=a[l++];
		}
		else{
			if(s2[l]%2==1||s1[r]%2==1){
				printf((n-r+l)%2==1?"Alice\n":"Bob\n");
				return 0;
			}
			else{
				printf((n-r+l)%2==1?"Bob\n":"Alice\n");
				return 0;
			}
		}
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}