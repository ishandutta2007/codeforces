#include<bits/stdc++.h>
using namespace std; 
int L,R,len,cnt,p[33][33],ds,i,j,ans,ll[33],rr[33];
//inline bool cmp(seg aa,seg bb){return aa.l<bb.l;}
int main(){
	cin>>L>>R;
	len=(R-L+1);
	cout<<"YES\n";
	if(L==R){
		cout<<"2 1\n1 2 "<<L<<"\n";return 0;
	}
	p[1][2]=1;ds=2;
	for(i=1;i<len;i<<=1){
		++ds;
		p[1][ds]=1;
		for(j=2;j<ds;++j)p[j][ds]=(1<<j-2);
	}
	if(i!=len){
		++ds;
		p[1][ds]=1;--len;
		for(i=2;i<ds;++i){
			if(len&(1<<i-2)){
				p[i][ds]=(len&((1<<i-2)-1))+1;
			}
		}
	}
	for(i=2;i<=ds;++i)if(p[1][i])p[1][i]+=L-1;
	for(i=1;i<=ds;++i)for(j=i+1;j<=ds;++j)ans+=p[i][j]>0;
	cout<<ds<<" "<<ans<<"\n";
	for(i=1;i<=ds;++i)for(j=i+1;j<=ds;++j)if(p[i][j])cout<<i<<" "<<j<<" "<<p[i][j]<<'\n';

}