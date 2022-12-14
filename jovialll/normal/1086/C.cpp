#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int n,k,i,to[30],fl,us[30];
char c[N],a[N],b[N];
void solve(int pos,int typ){//typ&1:typ&2 
	if(typ==3||pos>n){fl=0;return ;}
	if(~to[a[pos]]){
		if(((!(typ&1))&&to[a[pos]]>c[pos])||((!(typ&2))&&to[a[pos]]<b[pos]))return ;
		solve(pos+1,typ|(to[a[pos]]<c[pos])|((to[a[pos]]>b[pos])<<1));
		return ;
	}
	int j;
	if(typ==1){
		for(j=k-1;~j;--j)if(!us[j]){to[a[pos]]=j;us[j]=1;break;}
		if(to[a[pos]]<b[pos]){us[to[a[pos]]]=0,to[a[pos]]=-1;return ;}
		solve(pos+1,typ|((to[a[pos]]>b[pos])<<1));
		if(fl)us[to[a[pos]]]=0,to[a[pos]]=-1;
		return ;
	}
	if(typ==2){
		for(j=0;j<k;++j)if(!us[j]){to[a[pos]]=j;us[j]=1;break;}
		if(to[a[pos]]>c[pos]){us[to[a[pos]]]=0,to[a[pos]]=-1;return ;}
		solve(pos+1,typ|(to[a[pos]]<c[pos]));
		if(fl)us[to[a[pos]]]=0,to[a[pos]]=-1;
		return ;
	}
	for(j=b[pos];j<=c[pos];++j){
		if(!us[j]){
			to[a[pos]]=j;us[j]=1;
			solve(pos+1,typ|(to[a[pos]]<c[pos])|((to[a[pos]]>b[pos])<<1));
			if(fl)us[to[a[pos]]]=0,to[a[pos]]=-1;
			else return ;
		}
	}
}
int T,j,ii;
int main(){
	cin>>T;
	for(ii=1;ii<=T;++ii){
		scanf("%d%s%s%s",&k,a+1,b+1,c+1);
		n=strlen(a+1);
		for(i=1;i<=n;++i)a[i]-='a',b[i]-='a',c[i]-='a';
		memset(us,0,sizeof(us));memset(to,-1,sizeof(to));
		fl=1;solve(1,0);
		if(fl){
			cout<<"NO\n";
		}
		else{
			for(j=i=0;i<k;++i){
				while(us[j])++j;
				if(!~to[i])to[i]=j,++j;
			}
			cout<<"YES\n";
			for(i=0;i<k;++i)cout<<char('a'+to[i]);
			cout<<"\n";
		}
	}
	return 0;
}