#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
using std::cin;using std::cerr;
using std::max;using std::min;
#define N 1000005
#define P 666073
#define mod 19260817
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,m,ha[N],po[N],pos;
char s[N],ans[N];
int askhash(int l,int r) {return (ha[r]-(ll)ha[l-1]*po[r-l+1]%mod+mod)%mod;}
bool Compare(int l1,int r1,int l2,int r2)
{
	int len=r1-l1+1;
	for(;l2+len<=r2&&askhash(l1,r1)==askhash(l2,l2+len-1);l2+=len);
	int l=0,r=len,mid;
	for(;l<r;) mid=l+r+1>>1,askhash(l1,l1+mid-1)^askhash(l2,l2+mid-1)?r=mid-1:l=mid;
	if(l==r1-l1+1) return 1;
	return s[l1+l]<s[l2+l];
}
int main()
{
	scanf("%d%d%s",&n,&m,s+1),po[0]=1,n=min(n,m);
	for(int i=1;i<=n;i++) s[i+n]=s[i];
	for(int i=1;i<=n*2;i++) po[i]=(ll)po[i-1]*P%mod,ha[i]=((ll)ha[i-1]*P+s[i])%mod;
	pos=n;
	for(int i=1;i<n;i++) if(Compare(1,i,i+1,n)) {pos=i;break;}
	// dbg2(pos);
	for(int i=1;i<=m;i++) putchar(s[(i-1)%pos+1]);
	return 0;
}