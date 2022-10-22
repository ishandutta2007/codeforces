#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+9;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int ans;
struct node{
	int x,y;
	bool operator<(const node&X)const{
		return y<X.y;
	}
}a[N];
signed main(){
	int n=read();
	for(int i=1;i<=n;i++){
		a[i].x=read(),a[i].y=read();
	}
	sort(a+1,a+1+n);
	int j=n,now=0;
	for(int i=1;i<=n;i++){
		if(now<a[i].y){
			int need=a[i].y-now;
			while(need&&j){
				if(need>=a[j].x){
					need-=a[j].x;
					now+=a[j].x;
					ans+=a[j].x*2;
					a[j].x=0;
					j--;
				}else{
					a[j].x-=need;
					now+=need;
					ans+=need*2;
					need=0;
				}
			}
			if(!j){
				ans+=a[i].x*2;
				need+=a[i].x;
				a[i].x=0;
				continue;
			}
			ans+=a[i].x;
			now+=a[i].x;
			a[i].x=0;
		}else{
			ans+=a[i].x;
			now+=a[i].x;
			a[i].x=0;
		}
	}cout<<ans<<endl;
	return 0;
}