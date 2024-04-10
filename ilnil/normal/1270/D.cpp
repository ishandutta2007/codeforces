#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define mp make_pair
#define P pair<int,int>
using namespace std;
const int N=505;
int n,k,m;
int wz,a_wz;
int a[N];

bool bz[N];
void find(){
	printf("? ");
	fo(j,1,n)if(bz[j])printf("%d ",j);
	printf("\n");
	fflush(stdout);
	scanf("%d %d",&wz,&a_wz);
}
int main(){
	scanf("%d %d",&n,&k);
	fo(i,1,n)a[i]=-1;
	if(k<=n-k+1){
		fo(i,1,k)bz[i]=1;
		fo(i,1,k){
			find();
			a[wz]=a_wz;
			bz[wz]=0;
			bz[k+i]=1;
		}
		fo(i,1,n)bz[i]=0;
		int aa=0;
		fo(i,1,n)if(a[i]>-1){
			bz[i]=1;
			++aa;
			if(aa==k)break;
		}
		find();
		fo(i,1,n)if(a[i]>-1&&a[i]<=a_wz&&bz[i])++m;
		printf("! %d\n",m);
		fflush(stdout);
	}else{
		fo(i,1,k)bz[i]=1;
		fo(i,1,n-k+1){
			find();
			a[wz]=a_wz;
			bz[wz]=0;
			bz[k+i]=1;
		}
		int p2=0;
		int p=wz;
		fo(i,1,n)if(a[i]==-1&&!bz[i]){
			bz[i]=1;
			find();
			a[wz]=a_wz;
			if(a_wz<a[p]){
				++m;
			}
			p2=wz;
			bz[i]=0;
		}
		bz[p]=1;
		if(!p2)
			fo(i,1,n)if(a[i]>-1&&i!=p){
				p2=i;
				break;
			}
		fo(i,1,n)if(bz[i]&&i!=p){
			bz[i]=0;
			bz[p2]=1;
			
			find();
			
			m+=(a[p2]<a[p])^(wz!=p);
			bz[i]=1;
			bz[p2]=0;
		}
		printf("! %d\n",m+1);fflush(stdout);
	}
}