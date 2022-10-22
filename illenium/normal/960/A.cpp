#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
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

string s;

int main()
{
    cin>>s;
    int len=s.length(),a=0,b=0,c=0;
    bool aa=0,bb=0,cc=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='b'&& cc)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        if(s[i]=='a'&&(bb||cc))
        {
            cout<<"NO"<<endl;
            return 0;
        }
        if(s[i]=='a')
        {
            a++;aa=1;
        }
        else if(s[i]=='b') b++,bb=1;
        else c++,cc=1;
    }
    if(!a||!b||!c) cout<<"NO"<<endl;
    else if(c==a||c==b) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}