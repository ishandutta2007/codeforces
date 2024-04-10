#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;
typedef long long ll;
typedef double db;
void gn(int &x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c=='-')sg=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sg;
}
void gn(ll &x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c=='-')sg=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sg;
}
const int mo=1000000007;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int n,m;
char s[55][55];

int a[1111];
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)scanf("%s",s[i]+1);
    int cnt=0;
    for (int i=1;i<n;i++)
        for (int j=1;j<m;j++){
            a[s[i][j]]++;
            a[s[i][j+1]]++;
            a[s[i+1][j]]++;
            a[s[i+1][j+1]]++;
            if(a['f'] && a['a'] && a['c'] && a['e'])cnt++;
            a[s[i][j]]--;
            a[s[i][j+1]]--;
            a[s[i+1][j]]--;
            a[s[i+1][j+1]]--;
        }
    printf("%d\n",cnt);
    return 0;

}