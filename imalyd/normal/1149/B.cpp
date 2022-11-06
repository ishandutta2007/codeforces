#include<bits/stdc++.h>
using namespace std;
#define ll long long
namespace io{
    const int l=1<<19;
    char buf[l],*s,*t,c;
    char gc(){
        if(s==t){
            t=(s=buf)+fread(buf,1,l,stdin);
            return s==t?EOF:*s++;
        }
        return *s++;
    }
    template<class I>void gi(I &x){
        x=0;c=gc();while(c<'0'||c>'9')c=gc();
        while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=gc();}
    }
};
using io::gi;

const int N=100005;

int n,q,s[N],dp[251][251][251];
int t1,t2,t3,s1[N],s2[N],s3[N];
char ss[N];
set<int>S[26];
void upd(int &a,int b){if(a==-1||a>b)a=b;}
int main(){
	scanf("%d%d%s",&n,&q,ss+1);
	for(int i=1;i<=n;i++){
		s[i]=ss[i]-'a';
		S[s[i]].insert(i);
	}
	memset(dp,-1,sizeof(dp));
	dp[0][0][0]=0;
	while(q--){
		char A[3],C[3];int b,c;
		set<int>::iterator v;
		scanf("%s%d",A,&b);
		if(A[0]=='-'){
			if(b==1)--t1;
			if(b==2)--t2;
			if(b==3)--t3;
		}else{
			scanf("%s",C);c=C[0]-'a';
			if(b==1){
				s1[++t1]=c;
				for(int i=t1;i<=t1;i++)for(int j=0;j<=t2;j++)
					for(int k=0;k<=t3;k++){
						dp[i][j][k]=-1;
						if(i&&dp[i-1][j][k]!=-1){
							v=S[s1[i]].upper_bound(dp[i-1][j  ][k  ]);
							if(v!=S[s1[i]].end())upd(dp[i][j][k],*v);
						}
						if(j&&dp[i][j-1][k]!=-1){
							v=S[s2[j]].upper_bound(dp[i  ][j-1][k  ]);
							if(v!=S[s2[j]].end())upd(dp[i][j][k],*v);
						}
						if(k&&dp[i][j][k-1]!=-1){
							v=S[s3[k]].upper_bound(dp[i  ][j  ][k-1]);
							if(v!=S[s3[k]].end())upd(dp[i][j][k],*v);
						}
					}
			}
			if(b==2){
				s2[++t2]=c;
				for(int i=0;i<=t1;i++)for(int j=t2;j<=t2;j++)
					for(int k=0;k<=t3;k++){
						dp[i][j][k]=-1;
						if(i&&dp[i-1][j][k]!=-1){
							v=S[s1[i]].upper_bound(dp[i-1][j  ][k  ]);
							if(v!=S[s1[i]].end())upd(dp[i][j][k],*v);
						}
						if(j&&dp[i][j-1][k]!=-1){
							v=S[s2[j]].upper_bound(dp[i  ][j-1][k  ]);
							if(v!=S[s2[j]].end())upd(dp[i][j][k],*v);
						}
						if(k&&dp[i][j][k-1]!=-1){
							v=S[s3[k]].upper_bound(dp[i  ][j  ][k-1]);
							if(v!=S[s3[k]].end())upd(dp[i][j][k],*v);
						}
					}
			}
			if(b==3){
				s3[++t3]=c;
				for(int i=0;i<=t1;i++)for(int j=0;j<=t2;j++)
					for(int k=t3;k<=t3;k++){
						dp[i][j][k]=-1;
						if(i&&dp[i-1][j][k]!=-1){
							v=S[s1[i]].upper_bound(dp[i-1][j  ][k  ]);
							if(v!=S[s1[i]].end())upd(dp[i][j][k],*v);
						}
						if(j&&dp[i][j-1][k]!=-1){
							v=S[s2[j]].upper_bound(dp[i  ][j-1][k  ]);
							if(v!=S[s2[j]].end())upd(dp[i][j][k],*v);
						}
						if(k&&dp[i][j][k-1]!=-1){
							v=S[s3[k]].upper_bound(dp[i  ][j  ][k-1]);
							if(v!=S[s3[k]].end())upd(dp[i][j][k],*v);
						}
					}
			}
		}
//		for(int i=0;i<=t1;i++)for(int j=0;j<=t2;j++)
//			for(int k=0;k<=t3;k++)printf("dp[%d][%d][%d]=%d\n",i,j,k,dp[i][j][k]);
		if(dp[t1][t2][t3]==-1)puts("NO");else puts("YES");
	}
	return 0;
}