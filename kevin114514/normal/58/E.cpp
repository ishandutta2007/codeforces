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
string tostring(int x)//result is reversed!
{
	string res;
	while(x)
	{
		res+=(char)('0'+x%10);
		x/=10;
	}
	return res;
}
bool dp[15][7][7][8][8][8][2];
string aa[15][7][7][8][8][8][2];
string bb[15][7][7][8][8][8][2];
string cc[15][7][7][8][8][8][2];
int main()
{
	int a,b,c;
	scanf("%d+%d=%d",&a,&b,&c);
	string A=tostring(a),B=tostring(b),C=tostring(c);
	A+='%';
	B+='%';
	C+='%';
	dp[0][0][0][0][0][0][0]=1;
	for(int i=0;i<14;i++)
	for(int a0=0;a0<=6;a0++)
	for(int b0=0;b0<=6;b0++)
		for(int fa=0;fa<=7;fa++)
		for(int fb=0;fb<=7;fb++)
		for(int fc=0;fc<=7;fc++)
			for(int delta=0;delta<=1;delta++) if(dp[i][a0][b0][fa][fb][fc][delta])
			{
				for(int adda=9;adda>=0;adda--)
					for(int addb=9;addb>=0;addb--)
					{
						int sum=adda+addb+delta;
						int ndelta=sum/10;
						int addc=sum%10;
						int na0=a0;
						if(adda)
							na0=0;
						else	na0++;
						int nb0=b0;
						if(addb)
							nb0=0;
						else	nb0++;
						if(max(na0,nb0)<7)
						if(!dp[i+1][na0][nb0][fa+(bool)('0'+adda==A[fa])][fb+(bool)('0'+addb==B[fb])][fc+(bool)('0'+addc==C[fc])][ndelta])
						{
							dp[i+1][na0][nb0][fa+(bool)('0'+adda==A[fa])][fb+(bool)('0'+addb==B[fb])][fc+(bool)('0'+addc==C[fc])][ndelta]=1;
							aa[i+1][na0][nb0][fa+(bool)('0'+adda==A[fa])][fb+(bool)('0'+addb==B[fb])][fc+(bool)('0'+addc==C[fc])][ndelta]=aa[i][a0][b0][fa][fb][fc][delta]+(char)('0'+adda);
							bb[i+1][na0][nb0][fa+(bool)('0'+adda==A[fa])][fb+(bool)('0'+addb==B[fb])][fc+(bool)('0'+addc==C[fc])][ndelta]=bb[i][a0][b0][fa][fb][fc][delta]+(char)('0'+addb);
							cc[i+1][na0][nb0][fa+(bool)('0'+adda==A[fa])][fb+(bool)('0'+addb==B[fb])][fc+(bool)('0'+addc==C[fc])][ndelta]=cc[i][a0][b0][fa][fb][fc][delta]+(char)('0'+addc);
						}
					}
			}
	string ans="1145141919810+1919810114514=3064952034324";
	for(int i=0;i<=14;i++)
	for(int a0=0;a0<=6;a0++)
	for(int b0=0;b0<=6;b0++) if(dp[i][a0][b0][sz(A)-1][sz(B)-1][sz(C)-1][0])
	{
		string AA=aa[i][a0][b0][sz(A)-1][sz(B)-1][sz(C)-1][0];
		string BB=bb[i][a0][b0][sz(A)-1][sz(B)-1][sz(C)-1][0];
		string CC=cc[i][a0][b0][sz(A)-1][sz(B)-1][sz(C)-1][0];
		rev(AA);
		rev(BB);
		rev(CC);
		while(AA[0]=='0') AA=AA.substr(1);
		while(BB[0]=='0') BB=BB.substr(1);
		while(CC[0]=='0') CC=CC.substr(1);
		string res=AA+"+"+BB+"="+CC;
		if(sz(res)<sz(ans))
			ans=res;
	}
	cout<<ans<<endl;
	return 0;
}