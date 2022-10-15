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
		int a,b,c;
		cin>>a>>b>>c;
		c=a*b/2-c;
		if(b==1)
		{
			if(c*2==a*b)
				puts("YES");
			else	puts("NO");
			continue;
		}
		if(a==1)
		{
			if(!c)
				puts("YES");
			else	puts("NO");
			continue;
		}
		int black=(a+1)/2*b;
		int white=a*b-black;
		if((black-c)%2||(white-c)%2||(black<c)||(white<c))
		{
			puts("NO");
			continue;
		}
		swap(a,b);
		c=a*b/2-c;
		black=(a+1)/2*b;
		white=a*b-black;
		if((black-c)%2||(white-c)%2||(black<c)||(white<c))
			puts("NO");
		else	puts("YES");
	}
	return 0;
}