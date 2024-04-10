#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,x[500500],y[500500],res,l,r;
string s;
int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>s;
		l=r=0;
		for(auto i:s){
			if(i=='('){
				l++;
			}
			else{
				if(l){l--;}
				else{r++;}
			}
		}
		if(!l&&!r){x[0]++;continue;}
		if(!l){y[r]++;continue;}
		if(!r){x[l]++;continue;}
	}
	res+=x[0]/2;
	for(i=1;i<=500000;i++){
		res+=min(x[i],y[i]);
	}
	printf("%d",res);
}