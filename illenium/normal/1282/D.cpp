#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int cnta,cntb,tmp,pre;
vector <char> vec;

int main()
{
	for(int i=1;i<=300;i++) printf("a"); puts(""); cin>>cnta; pre=cnta; cnta=300-cnta;
	for(int i=1;i<=300;i++) printf("b"); puts(""); cin>>cntb; cntb=300-cntb;
	int len=cnta+cntb;
	pre=cntb;
	for(int i=1;i<=len-1;i++)
	{
		for(int j=0;j<vec.size();j++) printf("%c",vec[j]);
		printf("b");
		for(int j=1;j<=len-vec.size()-1;j++) printf("a"); puts("");
		cin>>tmp;
		if(tmp>cntb) vec.push_back('a'),cnta--;
		else vec.push_back('b'),cntb--;
	}
	if(cnta!=0) vec.push_back('a');
	else vec.push_back('b');
	for(int i=0;i<vec.size();i++) printf("%c",vec[i]);
	return 0;
}