#include<iostream>
#include<cmath> 
#include<cstdio>
#include<algorithm>
#define N 100005
#define MM 1000000007
#define INF 0x4fffffff
#define PI 3.14159265358979323846

#define rep(i,j,k) for(i=j;i<=k;i++)
#define rrep(i,j,k) for(i=j;i>=k;i--)

using namespace std;

int i,n,ma,num,a[200];
char s[200000];

long long pw(int x, int w){
	if (w==0)	
		return 1;
	else{
		long long tt;
		tt=pw(x,w>>1);
		tt=(tt*tt)%MM;
		if (w%2==1)
			tt=(tt*x)%MM;
		return tt;
	}
}

int main(){
	cin>>n;
	gets(s);
	gets(s);
	a['A']=a['C']=a['G']=a['T']=0;
	rep(i,1,n)
		a[s[i-1]]++;
	ma=a['A'];
	if (a['C']>ma)
		ma=a['C'];
	if (a['G']>ma)
		ma=a['G'];
	if (a['T']>ma)
		ma=a['T'];
	num=0;
	if (a['A']==ma)
		num++;	
	if (a['C']==ma)
		num++;	
	if (a['G']==ma)
		num++;	
	if (a['T']==ma)
		num++;
	if (num==1)
		cout<<1<<endl;
	else
		cout<<pw(num,n)%MM<<endl;	
	return 0;
}