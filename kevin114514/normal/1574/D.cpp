#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
#pragma comment(linker, "/STACK:16777216")
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define ll long long
#define ull ll
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
void die(string S){puts(S.c_str());exit(0);}
const ull mod=20000007;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
inline ull getHash(vector<int> build)
{
	ull hash=0;
	for(int i=0;i<sz(build);i++)
		hash=(hash*190503+build[i])%mod;
	return hash;
}
vector<int> slot[11];
inline ll sum(vector<int> build)
{
	ll ans=0;
	for(int i=0;i<sz(build);i++)
		ans+=slot[i][build[i]];
	return ans;
}
bitset<20000009> ban;
//ll sum;
ll ans;
vector<int> res(10,0);
ull Hash;
ull base[11];
vector<int> bb[100100];
int main()
{
//	st=clock();
	base[0]=1;
	for(int i=0;i<10;i++)
		base[i+1]=base[i]*190503%mod;
	int n=read();
	vector<int> ori;
	for(register int i=0;i<n;i++)
	{
		int c=read();
		ori.pb(c-1);
		while(c--)
		{
			int x=read();
			slot[i].pb(x);
//			if(!c)
//				sum+=x;
		}
	}
//	cout<<sum<<endl;
	Hash=getHash(ori);
	int m=read();
	for(int i=0;i<m;i++)
	{
		vector<int> b;
		for(int i=0;i<n;i++)
		{
			int x=read();
			b.pb(x-1);
		}
		bb[i]=b;
		ban[getHash(b)]=1;
	}
	if(!ban[Hash])
	{
		for(int i=0;i<n;i++)
			cout<<ori[i]+1<<" ";
		return 0;
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			if(bb[i][j])
			{
				bb[i][j]--;
				if(sum(bb[i])>ans&&!ban[getHash(bb[i])])
				{
					ans=sum(bb[i]);
					res=bb[i];
				}
				bb[i][j]++;
			}
	}
	for(int i=0;i<n;i++)
		cout<<res[i]+1<<" ";
	return 0;
}