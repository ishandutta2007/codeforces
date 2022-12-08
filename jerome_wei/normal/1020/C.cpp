#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
long long INF=100000000000000000000;
int v[3010];
ll c[3010];
int p[3010];
int n,m;
bool cmp(const int a,const int b){
    return c[a]<c[b];
}
int gt[3010];
int mxt=0;
int del[3010];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
	scanf("%d%lld",&v[i],&c[i]);
	gt[v[i]]++;
	p[i]=i;
    }
    for(int i=2;i<=m;i++)
		mxt=max(mxt,gt[i]);
    sort(p+1,p+n+1,cmp);
    if(mxt<gt[1]){
    	printf("0\n"); 
    	return 0;
    }
    ll Ans=INF;
    for(int lm=gt[1];lm<=mxt;lm++){
	ll ans=0;
	int k=lm-gt[1]+1;
	for(int i=2;i<=m;i++)
	{
	    del[i]=max(0,gt[i]-lm);
		k-=del[i];
	}
	del[0]=max(0,k);
	for(int i=1;i<=n;i++){
	    int pos=p[i];
	    int t=v[pos];
		if(t==1)continue;
		if(del[t]){
			ans+=c[pos],del[t]--;
	    }
	    else{
		if(del[0]){
		    ans+=c[pos],del[0]--;
		}
	    }
	}
	//cout<<ans<<endl;
	Ans=min(ans,Ans);
    }
    if(Ans==INF)Ans=0;
    printf("%lld\n",Ans);
}