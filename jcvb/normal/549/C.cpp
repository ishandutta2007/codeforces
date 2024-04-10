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

int n,k;
int a[2];

int las;
void testgo(int f){
    if(a[0]==0)a[1]--;
    else if(a[1]==0)a[0]--;
    else{
        if(a[1]+a[0]==k+1){
            if(a[1]%2==f)a[0]--;
            else a[1]--;
        }else{
            if(k%2==0){
                if(f==0){
                    if(a[0]>a[1])a[1]--;
                    else a[0]--;
                }else if(a[0]>a[1])a[0]--;
                else a[1]--;
            }else{
                if(f==0)a[1]--;
                else a[0]--;
            }
        }
    }
}
int test(){
    int f=1;
    while(a[0]+a[1]>k){
        testgo(f);
        f^=1;
    }
    if(a[1]%2==1)return 1;
    else return 0;
}
int main()
{
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        a[x%2]++;
    }
    int ans=test();
    if(ans)printf("Stannis\n");
    else printf("Daenerys\n");
    return 0;
}