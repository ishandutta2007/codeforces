#include<bits/stdc++.h>
//AtCoder Library
//#define ATCODER
#ifdef ATCODER
#include<atcoder/convolution.hpp>
#include<atcoder/dsu.hpp>
#include<atcoder/fenwicktree.hpp>
#include<atcoder/internal_bit.hpp>
#include<atcoder/internal_math.hpp>
#include<atcoder/internal_queue.hpp>
#include<atcoder/internal_scc.hpp>
#include<atcoder/internal_type_traits.hpp>
#include<atcoder/lazysegtree.hpp>
#include<atcoder/math.hpp>
#include<atcoder/maxflow.hpp>
#include<atcoder/mincostflow.hpp>
#include<atcoder/modint.hpp>
#include<atcoder/scc.hpp>
#include<atcoder/segtree.hpp>
#include<atcoder/string.hpp>
#include<atcoder/twosat.hpp>
using namespace atcoder;
#endif
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
void die(string S){puts(S.c_str());exit(0);}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string S;
		cin>>S;
		int ans=10;
		for(int i=0;i<1024;i++)
		{
			bool flag=true;
			for(int j=0;j<10;j++)
				if(isdigit(S[j])&&S[j]-'0'!=(i>>j&1))
					flag=false;
			if(!flag)
				continue;
			int cnt[2];
			cnt[0]=cnt[1]=0;
			for(int j=0;j<10;j++)
			{
				cnt[j%2]+=(i>>j&1);
				if(cnt[0]+(10-j-1)/2<cnt[1]||cnt[1]+(10-j)/2<cnt[0])
					ans=min(ans,j+1);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}