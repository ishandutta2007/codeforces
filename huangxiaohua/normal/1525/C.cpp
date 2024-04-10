#include<bits/stdc++.h>
using namespace std;

int i,j,k,n,m1,m[2],res[300500],t,it;
struct sb{
	int id,w,p;
	bool operator<(const sb x)const{return w<x.w;}
}s1[300500],s[2][300500];

void get(sb x,sb y){
	if(x.p==-1&&y.p==-1){res[x.id]=res[y.id]=(x.w+y.w)/2;}
	if(x.p==-1&&y.p==1){res[x.id]=res[y.id]=(2*m1+x.w-y.w)/2;}
	if(x.p==1&&y.p==-1){res[x.id]=res[y.id]=(-x.w+y.w)/2;}
	if(x.p==1&&y.p==1){res[x.id]=res[y.id]=(2*m1-x.w-y.w)/2;}
}

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m1;m[0]=m[1]=0;
		memset(res,-1,n*4+50);
		for(i=1;i<=n;i++){s1[i].id=i;cin>>s1[i].w;}
		for(i=1;i<=n;i++){
			string st;cin>>st;
			if(st=="L"){s1[i].p=-1;}else{s1[i].p=1;}
		}
		sort(s1+1,s1+n+1);
		for(i=1;i<=n;i++){
			it=s1[i].w&1;s[it][++m[it]]=s1[i];
			if((s[it][m[it]-1].p==-1&&s[it][m[it]].p==-1)||(s[it][m[it]-1].p==1&&s[it][m[it]].p==-1)){get(s[it][m[it]-1],s[it][m[it]]);m[it]-=2;}
		}
		for(i=0;i<=1;i++){while(m[i]>=2){get(s[i][m[i]-1],s[i][m[i]]);m[i]-=2;}}
		for(i=1;i<=n;i++){cout<<res[i]<<' ';}cout<<'\n';
	}
}