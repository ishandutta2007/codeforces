#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((!isdigit(ch))&&(ch!='-')) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
long long Testing,m,d,w,ans,i;
int main() {
    int Testing=read();
    for (;Testing;Testing--){
    	m=read();d=read();m=min(m,d);w=read();ans=0;
    	if (d==1){
    		printf("%lld\n",m*(m-1)/2);continue;
		}
		w/=__gcd(w,d-1);
		//iw 
        printf("%lld\n",(m/w)*m-(1+m/w)*(m/w)/2*w);
	}
    return 0;
}