#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
 
int j,k,n,t,i,m,a[1050],b[1050],l1,l2,mx,sb1,sb2;
vector<int> sb,x,y,v[1005000],resx1,resx2,resy1,resy2;
bool dp[1005000],yes,tmp[1050];
queue<int> q;
bool cmp(int x,int y){return x>y;}
 
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);l1=l2=0;yes=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);l1+=a[i];
		}
		scanf("%d",&m);
		for(i=1;i<=m;i++){
			scanf("%d",&b[i]);l2+=b[i];
		}
		if(n!=m||l2%2||l1%2){puts("nO");continue;}
		l1/=2;l2/=2;
		
		queue<int> clr;swap(q,clr);
		memset(dp,0,sizeof(bool)*(l1+5));
		sb.clear();sb.push_back(0);
		for(i=1;i<=n;i++){
			for(j=0;j<sb.size();j++){
				if(sb[j]+a[i]<=l1&&!dp[sb[j]+a[i]]){
					
					dp[sb[j]+a[i]]=1;q.push(sb[j]+a[i]);
					v[sb[j]+a[i]]=v[sb[j]];
					v[sb[j]+a[i]].push_back(i);
				}
			}
			if(dp[l1]){yes=1;break;}
			while(!q.empty()){sb.push_back(q.front());q.pop();}
		}
		if(!yes){puts("nO");continue;}
		x=v[l1];
		
		queue<int> clr2;swap(q,clr2);
		yes=0;memset(dp,0,sizeof(bool)*(l2+5));
		sb.clear();sb.push_back(0);
		for(i=1;i<=m;i++){
			for(j=0;j<sb.size();j++){
				if(sb[j]+b[i]<=l2&&!dp[sb[j]+b[i]]){
					dp[sb[j]+b[i]]=1;q.push(sb[j]+b[i]);
					v[sb[j]+b[i]]=v[sb[j]];
					v[sb[j]+b[i]].push_back(i);
				}
			}
			if(dp[l2]){yes=1;break;}
			while(!q.empty()){sb.push_back(q.front());q.pop();}
		}
		if(!yes){puts("nO");continue;}
		y=v[l2];
		
		memset(tmp,0,sizeof(tmp));
		for(i=0;i<x.size();i++){tmp[x[i]]=1;}resx2.clear();resx1.clear();
		for(i=1;i<=n;i++){if(!tmp[i]){resx2.push_back(a[i]);}else{resx1.push_back(a[i]);}}
		
		memset(tmp,0,sizeof(tmp));
		for(i=0;i<y.size();i++){tmp[y[i]]=1;}resy2.clear();resy1.clear();
		for(i=1;i<=m;i++){if(!tmp[i]){resy2.push_back(b[i]);}else{resy1.push_back(b[i]);}}
		if(resx1.size()>resx2.size()){swap(resx1,resx2);}
		if(resy1.size()<resy2.size()){swap(resy1,resy2);}
		
		sort(resx1.begin(),resx1.end(),cmp);sort(resx2.begin(),resx2.end(),cmp);sort(resy1.begin(),resy1.end());sort(resy2.begin(),resy2.end());
		
		for(i=0;i<resx2.size();i++){resx1.push_back(-resx2[i]);}
		for(i=0;i<resy2.size();i++){resy1.push_back(-resy2[i]);}
		
		sb1=sb2=0;
		puts("yES");
		for(i=0;i<n;i++){
			sb1+=resx1[i];
			printf("%d %d\n",sb1,sb2);
			sb2+=resy1[i];
			printf("%d %d\n",sb1,sb2);
		}
	}
}