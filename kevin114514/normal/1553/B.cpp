#include<bits/stdc++.h>
//AtCoder Library
//#define ATCODER
//#ifdef ATCODER
//#include<atcoder/convolution.hpp>
//#include<atcoder/dsu.hpp>
//#include<atcoder/fenwicktree.hpp>
//#include<atcoder/internal_bit.hpp>
//#include<atcoder/internal_math.hpp>
//#include<atcoder/internal_queue.hpp>
//#include<atcoder/internal_scc.hpp>
//#include<atcoder/internal_type_traits.hpp>
//#include<atcoder/lazysegtree.hpp>
//#include<atcoder/math.hpp>
//#include<atcoder/maxflow.hpp>
//#include<atcoder/mincostflow.hpp>
//#include<atcoder/modint.hpp>
//#include<atcoder/scc.hpp>
//#include<atcoder/segtree.hpp>
//#include<atcoder/string.hpp>
//#include<atcoder/twosat.hpp>
//using namespace atcoder;
//#endif
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
		string S,T;
		cin>>S>>T;
		bool ok=false;
		for(int i=0;i<S.length();i++)
			for(int j=i;j<S.length();j++)
			{
				int len=j-i+1;
				if(S.substr(i,len)==T.substr(0,len))
				{
					bool f=true;
					for(int x=len;x<T.length();x++)
						if(j-(x-len)-1<0||S[j-(x-len)-1]!=T[x])
							f=false;
					if(f)
						ok=true;
				}
			}
		if(ok)
			puts("YES");
		else	puts("NO");
	}
	return 0;
}