#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,t,n,m,res,cur=-1,sb,tmp,t1;

int main() {
	ios::sync_with_stdio(0);
	cin>>n>>t>>m;
	while(t--){
		cin>>sb;
		sb-=tmp;
		if(sb<=cur){

		}
		else{
			res++;
			sb-=t1;
			cur=(sb+m-1)/m;
			cur*=m;
			tmp+=t1;
			t1=0;
		}
		t1++;
		//printf("NMSL%d %d %d\n",sb,tmp,cur);
	}
	cout<<res;
}