#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
int a[500500],b[500500];

int main() {
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
    	cin>>n;
    	m=0;
    	int sb=0,T=n-1;
    	for(i=1;i<=n;i++){
    		cin>>k;
    		if(!k){
    			sb++;
			}
			else a[++m]=k;
		}
		if(!m){
			cout<<"0\n";continue;
		}
		n=m;m=0;
		a[0]=0;
		sort(a+1,a+n+1);
		while(T--){
			//cout<<"NMSL "<<sb<<endl;
			//for(i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
			if(sb){
				for(i=1;i<=n;i++){
					k=a[i]-a[i-1];
					if(!k)sb++;
					else b[++m]=k;
				}
				sb--;
			}
			else{
				for(i=2;i<=n;i++){
					k=a[i]-a[i-1];
					if(!k)sb++;
					else b[++m]=k;
				}
			}
			n=m;m=0;
			if(!n){
				a[1]=0;break;
			}
			memcpy(a,b,n*4+50);
			sort(a+1,a+n+1);
		}
		cout<<a[1]<<'\n';
	}
}