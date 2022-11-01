#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define put putchar
#define pb push_back
#define P pair<int,int>
#define F first
#define S second
#define ll long long
using namespace std;
const int N=3e5+5,M=6e5+5;
int n,a[N],p[N],wz[N],al,ar,ds;
int mx[19][N],lg[N];
int l,r,K;
int st[M],ss,la[M],fx[M],b[M];
P d[M],st2[M],fl[M];
bool bz[M];
ll ans;
#define qu(l,r)(K=lg[r-l],max(mx[K][l],mx[K][r-(1<<K)+1]))
int main(){
	cin>>n;
	fo(i,1,n)scanf("%d%d",&l,&r),a[l]=r,p[r]=l;
	fo(i,2,n)lg[i]=lg[i>>1]+1;
	fo(i,1,n)mx[0][i]=p[i];
	fo(i,1,lg[n]){
		int nx=1<<i-1;
		fo(j,1,n-nx+1)mx[i][j]=max(mx[i-1][j],mx[i-1][j+nx]);
	}
	fo(i,1,n){
		d[++ds]=P(i,i);wz[i]=ds;bz[ds]=1;
		st[++ss]=ds;st2[ss]=P(a[i],a[i]);
		for(;;){
			bool is=1;
			l=st2[ss].F;r=st2[ss].S;
			fd(j,1,ss-1){
				l=min(l,st2[j].F);r=max(r,st2[j].S);
				if(qu(l,r)>i){
					la[ss]=j;fl[ss]=P(l,r);break;
				}
				if(r-l==i-d[st[j]].F){
					is=0;
					if(j==ss-1){
						if(!bz[st[j]]&&fx[j]*(st2[ss].F-st2[j].F)>0){
							d[st[j]].S=i;
							b[st[j]]++;
							--ss;
						}else{
							fx[j]=st2[ss].F>st2[j].F?1:-1;
							d[++ds]=P(d[st[j]].F,i);
							b[ds]=2;
							st[--ss]=ds;
						}
					}else{
						d[++ds]=P(d[st[j]].F,i);bz[ds]=1;
						st[ss=j]=ds;
					}
					st2[j]=P(l,r);
					break;
				}
				if(la[j]){
					l=min(l,fl[j].F);r=max(r,fl[j].S);
					j=la[j]+1;
				}
			}
			if(is)break;
		}
	}
	if(ss>1)bz[++ds]=1;
	fo(i,1,ds)if(!bz[i])ans+=(ll)b[i]*(b[i]-1)/2-1;
	cout<<ans+ds;
}