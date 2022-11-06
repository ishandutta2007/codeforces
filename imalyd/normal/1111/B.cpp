#include<bits/stdc++.h>
using namespace std;
#define int long long
int rd(){
    int a=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))a=(a<<1)+(a<<3)+(ch^48),ch=getchar();
    return a;
}

const int N=1000005;

int n,k,m,a[N],sum;
double ans;
signed main(){
    n=rd(),k=rd(),m=rd();
	for(int i=1;i<=n;i++)a[i]=rd();sort(a+1,a+n+1),reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum+=a[i];
		if(m-n+i>=0){
			int M=min(i*k,m-n+i);
			double s=((double)(sum+M))/((double)i);
			if(ans<s)ans=s;
		}
	}
	printf("%.12lf",ans);
    return 0;
}