#include<bits/stdc++.h>
using namespace std;
#define mid (l+r>>1)
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef long double ld;
ll mod=1e9+7;
const ld pi=acos(-1.L);
const ld eps=3e-17;
const int mn=2e3+10;
int h[102][26];
int ans[102];
int main() {
    int n;
    scanf("%d", &n);
    if(n<=3){
        string s,t;
        for(int i=1;i<=n;i++)printf("? %d %d\n",i,i),fflush(stdout),cin>>t,s+=t;
        printf("! %s\n",s.c_str());
        fflush(stdout);
        return 0;
    }
    printf("? 1 %d\n",n/2);
    fflush(stdout);
    for(int i=0;i<(n/2)*(n/2+1)/2;i++){
        string s;
        cin>>s;
        for(char c:s)h[s.size()][c-'a']++;
    }
    printf("? 2 %d\n",n/2);
    fflush(stdout);
    for(int i=0;i<(n/2-1)*(n/2)/2;i++){
        string s;
        cin>>s;
        for(char c:s)h[s.size()][c-'a']--;
    }
    for(int i=n/2;i>=2;i--)for(int j=0;j<26;j++)h[i][j]-=h[i-1][j];
    for(int i=1;i<=n;i++)for(int j=0;j<26;j++)if(h[i][j])ans[i]=j;
    printf("? 1 %d\n",n);
    fflush(stdout);
    memset(h,0,sizeof(h));
    for(int i=0;i<(n)*(n+1)/2;i++){
        string s;
        cin>>s;
        for(char c:s)h[s.size()][c-'a']++;
    }
    for(int i=n/2+1;i<=n;i++){
        for(int j=1;j<=n/2;j++){
            h[i][ans[j]]-=min(j,n+1-i);
        }
    }
    for(int i=n/2+1;i<=n;i++){
        for(int j=0;j<26;j++)if(h[i][j]-h[i+1][j])ans[i]=j;
        for(int j=i+1;j<=n;j++)h[j][ans[i]]-=n+1-j;
    }
    printf("! ");
    for(int i=1;i<=n;i++)printf("%c",ans[i]+'a');
    printf("\n");
    fflush(stdout);
}