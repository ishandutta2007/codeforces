#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
void die(string S){puts(S.c_str());exit(0);}
int main()
{
	int acdg,abdf,abce,bcfg,bdeg,cdef;
	cin>>acdg>>abdf>>abce>>bcfg>>bdeg>>cdef;
	int sum=1e9,aa,bb,cc,dd,ee,ff,gg;
	for(int g=0;g<=1e5;g++)
	{
		int bcf=bcfg-g;
		int bde=bdeg-g;
		int acd=acdg-g;
		int c2=acd+bcf-abdf;
		if(c2%2)
			continue;
		int c=c2/2;
		int bf=bcf-c;
		int ad=acd-c;
		int d2=acd+bde-abce;
		if(d2%2)
			continue;
		int d=d2/2;
		int a=ad-d;
		int b2=bcf+bde-cdef;
		if(b2%2)
			continue;
		int b=b2/2;
		int f=bf-b;
		int e=bdeg-b-d-g;
		if(a>=0&&b>=0&&c>=0&&d>=0&&e>=0&&f>=0&&a+b+c+d+e+f+g<=sum)
		{
			sum=a+b+c+d+e+f+g;
			aa=a;
			bb=b;
			cc=c;
			dd=d;
			ee=e;
			ff=f;
			gg=g;
		}
//		cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<" "<<g<<endl;
	}
	if(sum==1e9)
		die("-1");
	cout<<sum<<endl;
	cout<<string(sum,'a')<<endl;
	for(int i=0;i<aa;i++) cout<<"b";
	for(int i=0;i<bb;i++) cout<<"a";
	for(int i=0;i<cc;i++) cout<<"b";
	for(int i=0;i<dd;i++) cout<<"b";
	for(int i=0;i<ee;i++) cout<<"a";
	for(int i=0;i<ff;i++) cout<<"a";
	for(int i=0;i<gg;i++) cout<<"b";
	puts("");
	for(int i=0;i<aa;i++) cout<<"b";
	for(int i=0;i<bb;i++) cout<<"b";
	for(int i=0;i<cc;i++) cout<<"a";
	for(int i=0;i<dd;i++) cout<<"b";
	for(int i=0;i<ee;i++) cout<<"a";
	for(int i=0;i<ff;i++) cout<<"b";
	for(int i=0;i<gg;i++) cout<<"a";
	puts("");
	for(int i=0;i<aa;i++) cout<<"b";
	for(int i=0;i<bb;i++) cout<<"b";
	for(int i=0;i<cc;i++) cout<<"b";
	for(int i=0;i<dd;i++) cout<<"a";
	for(int i=0;i<ee;i++) cout<<"b";
	for(int i=0;i<ff;i++) cout<<"a";
	for(int i=0;i<gg;i++) cout<<"a";
	puts("");
	return 0;
}