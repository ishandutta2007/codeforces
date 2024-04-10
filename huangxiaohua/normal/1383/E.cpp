#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007
int i,j,k,t,n,m,it=1,cur=-1;
ll l,r,res=1,cl,cr,w,tmp;
string sb;
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}
struct sb{int l,r;ll w;}s[1005000];
int main(){
	s[1].l=1;s[1].r=1e6+5;
	cin>>sb;
	for(auto i:sb){
		if(i=='0'){
			if(cur==-1)l++;
			else cur++;
		}
		else{
			if(cur>=0){
				tmp=res;
				while(s[it].l<=cur){
					cl=s[it].l;cr=s[it].r;w=s[it].w;
					if(cr>cur){s[it].l=cur+1;cr=cur;}
					else it--;
					res=(res+(cr-cl+1)*su(tmp,M-w))%M;
				}
				s[++it].l=1;s[it].r=cur;s[it].w=tmp;
			}
			cur=1;
		}
	}
	if(cur==-1){cout<<l;return 0;}
	l++;
	if(cur>0){r=cur;}
	cout<<res*l%M*r%M;
}