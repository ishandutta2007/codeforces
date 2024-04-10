#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;
typedef long long ll;
typedef double db;
const db pi=acos(-1);
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
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int n;


multiset<int>se;
int tot;

int ans[555];
int main()
{
    scanf("%d",&n);
    tot=n*n;
    for (int i=1;i<=tot;i++){
        int x;scanf("%d",&x);
        se.insert(x);
    }
    for (int i=n;i>=1;i--){
        int y=*se.rbegin();
        se.erase(se.find(y));
        for (int j=i+1;j<=n;j++){
            int d=gcd(y,ans[j]);
            se.erase(se.find(d));
            se.erase(se.find(d));
        }
        ans[i]=y;
    }
    for (int i=n;i>=1;i--)printf("%d ",ans[i]);
    printf("\n");
    return 0;
}