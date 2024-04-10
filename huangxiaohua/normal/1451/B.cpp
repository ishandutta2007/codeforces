#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
 
int i,j,k,n,t,res,q,l,r,m,cnm,j1,j2;
string sb,s[105],tmp,sb2;
 
void add(int k){
	s[k].clear();
	for(int i=1;i<=n;i++){
		if(i==k){continue;}
		s[k]+=sb[i];
	}
}
 
void gett(int l ,int r){
	tmp.clear();tmp+="x";
	for(int i=l;i<=r;i++){
		tmp+=sb[i];
	}
}
 
int main(){
	cin>>t;
	while(t--){
		cin>>n>>q>>sb2;
		sb.clear();sb+="x";cnm=0;
		sb+=sb2;
		while(q--){
			cin>>l>>r;res=0;j1=j2=0;
			gett(l,r);

			m=tmp.size()-1;i=j=1;
			for(;i<=n;i++){
				if(sb[i]==tmp[j]){if(!j1){j1=i;}j++;}
				if(j>m){j--;j2=i;}
			}
			//printf("%d %d %d %d\n",j1,j2,l,r);
			if(j2-j1>r-l){puts("YES");
			}else{puts("NO");
			}
			aaa:;
		}
	}
}