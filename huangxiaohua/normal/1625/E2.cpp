#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int i,j,k,n,m,t,l=1,r,id[300500],it,a[300500],st[300500],sb,cl[300500],cr[300500],cc[300500],L[300500],R[300500];
ll res[300500],ans;
#define N 4500
struct sb{
	int id,l,r,t;
	bool operator<(const sb x)const{
		if((l/N)!=(x.l/N))return (l/N)<(x.l/N);
		if((r/N)!=(x.r/N))return (r/N)<(x.r/N);
		return (t/N)<(x.t/N);
	}
}q[300500];
char s[300500];
int main() {
	ios::sync_with_stdio(0);
	cin>>n>>t>>s+1;
	for(i=1;i<=n;i++){
		if(s[i]=='(')st[++k]=i;
		else{
			if(!k)continue;
			j=0;
			if(s[st[k]-1]==')')j=id[st[k]-1];
			if(!j)j=++it;
			id[st[k]]=id[i]=j;
			R[st[k]]=i;L[i]=st[k];
			k--;
		}
	}
	it=0;j=0;
	for(i=1;i<=t;i++){
		cin>>sb;
		if(sb==1){it++;cin>>cl[it]>>cr[it];cc[it]=id[cl[it]];}
		else{j++;cin>>q[j].l>>q[j].r;q[j].id=j;q[j].t=it;}
	}
	t=j;k=0;
	sort(q+1,q+t+1);
	for(i=1;i<=t;i++){
		while(k<q[i].t){k++;if(l<=cl[k]&&r>=cr[k]&&id[cl[k]]){ans-=a[id[cl[k]]]--;}id[cl[k]]=id[cr[k]]=0;}
		while(k>q[i].t){id[cl[k]]=id[cr[k]]=cc[k];if(l<=cl[k]&&r>=cr[k]&&id[cl[k]]){ans+=++a[id[cl[k]]];}k--;}
		while(l>q[i].l){l--;if(s[l]=='('&&id[l]&&R[l]<=r){ans+=++a[id[l]];}}
		while(l<q[i].l){if(s[l]=='('&&id[l]&&R[l]<=r){ans-=a[id[l]]--;}l++;}
		while(r>q[i].r){if(s[r]==')'&&id[r]&&L[r]>=l){ans-=a[id[r]]--;}r--;}
		while(r<q[i].r){r++;if(s[r]==')'&&id[r]&&L[r]>=l){ans+=++a[id[r]];}}
		res[q[i].id]=ans;
	}
	for(i=1;i<=t;i++)cout<<res[i]<<'\n';
}//