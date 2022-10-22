#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
const int sg[]={0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12,14};
typedef long long ll;
int n,tot;
bool vis[100005];
int main(){
    scanf("%d",&n); tot=1;
    ll ans=1;
    for (ll i=2;i<=sqrt(n);i++){
	    if (!vis[i]){
	        int num=0;
	        for (ll j=i;j<=n;j*=i){
	            if (j<=sqrt(n)) vis[j]=true;
	            else tot++;
	            num++;
	        }
	        ans^=sg[num];
	    }
	    tot++;
	}
    ans^=(n-tot)&1;
    if (!ans) puts("Petya");
    else puts("Vasya");
    return 0;
}