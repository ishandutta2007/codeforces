#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define mp make_pair
#define P pair<int,int>
using namespace std;
const int N=2e5+5;
int T,n,a[N];
ll s,xa;
int main(){
	ios::sync_with_stdio(0);
	for(cin>>T;T--;){
		cin>>n;
		s=0;xa=0;
		fo(i,1,n)cin>>a[i],s+=a[i],xa^=a[i];
		if(s==xa*2){
			printf("0\n");
			printf("\n");
		}else{
			printf("1\n");
			ll b=0;
			int nd=0;
			fo(i,0,58){
				if(nd^((s&(1LL<<i))>0)){
					b+=1LL<<i;
					s+=1LL<<i;
					xa^=1LL<<i;
				}
				nd=(xa&(1LL<<i))>0;
			}
			printf("%lld\n",b);
		}
		
	}
}