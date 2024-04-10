#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51; 
map<string,ll>mp;
ll n,totn,totid,x,id,p,limit=1e9;
string op,str;
ll rt[MAXN<<2],rt2[MAXN<<2],sm[MAXN<<6],ls[MAXN<<6],rs[MAXN<<6];
inline ll read()
{
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=getchar();
    }
    if(ch=='-')
    {
        neg=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num*neg;
}
inline ll getId(string s)
{
	return mp.find(s)==mp.end()?mp[s]=++totid:mp[s];
}
inline void update(ll node)
{
	sm[node]=sm[ls[node]]+sm[rs[node]];
}
inline ll add(ll l,ll r,ll pos,ll val,ll node)
{
	ll cur=++totn;
	ls[cur]=ls[node],rs[cur]=rs[node];
	if(l==r)
	{
		return sm[cur]=sm[node]+val,cur;
	}
	ll mid=(l+r)>>1;
	if(pos<=mid)
	{
		ls[cur]=add(l,mid,pos,val,ls[node]);
	}
	else
	{
		rs[cur]=add(mid+1,r,pos,val,rs[node]);
	}
	return update(cur),cur;
}
inline ll query(ll l,ll r,ll ql,ll qr,ll node)
{
	if(ql<=l&&qr>=r)
	{
		return sm[node];
	}
	ll mid=(l+r)>>1,res=0;
	res+=ql<=mid?query(l,mid,ql,qr,ls[node]):0;
	res+=qr>mid?query(mid+1,r,ql,qr,rs[node]):0;
	return res;
}
int main()
{
	n=read();
	for(register int i=1;i<=n;i++)
	{
		cin>>op,rt[i]=rt[i-1],rt2[i]=rt2[i-1];
		if(op=="set")
		{
			cin>>str,x=read(),id=getId(str),p=query(1,limit,id,id,rt2[i]);
			p?rt[i]=add(1,limit,p,-1,rt[i]):1;	
			rt[i]=add(1,limit,x,1,rt[i]),rt2[i]=add(1,limit,id,x-p,rt2[i]);
		}
		if(op=="remove")
		{
			cin>>str,id=getId(str),p=query(1,limit,id,id,rt2[i]);
			p?rt[i]=add(1,limit,p,-1,rt[i]):1,rt2[i]=add(1,limit,id,-p,rt2[i]);
		}
		if(op=="undo")
		{
			x=read(),rt[i]=rt[i-x-1],rt2[i]=rt2[i-x-1];
		}
		if(op=="query")
		{
			cin>>str,id=getId(str),p=query(1,limit,id,id,rt2[i]);
			cout<<(p==0||p==1?p-1:query(1,limit,1,p-1,rt[i]))<<endl;
		}
	}
}