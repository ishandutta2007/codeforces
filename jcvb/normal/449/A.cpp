#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
int n,m,k;
int tmp[1000000];int tot=0;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    if(k>(n-1)+(m-1)){
        printf("-1\n");
        return 0;
    }
    k+=2;
    ll ma=0;
    int nex;
    for (int a=1;a<=n && k-a>=1;a=nex+1){
    	nex=n/(n/a);
    	tmp[tot++]=a;
    }
    for (int b=1;b<=m && k-b>=1;b=nex+1){
    	nex=m/(m/b);
    	tmp[tot++]=k-b+1;
    }tmp[tot++]=n;tmp[tot++]=k-m;
	sort(tmp,tmp+tot);
	for (int i=0;i<tot;i++)if(tmp[i] && k-tmp[i])ma=max(ma,1ll*(n/tmp[i])*(m/(k-tmp[i])));
    cout<<ma<<endl;
    return 0;
}