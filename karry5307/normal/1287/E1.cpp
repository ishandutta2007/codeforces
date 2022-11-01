#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef vector<string> vs;
const ll MAXN=1e5+51;
ll cnt;
string res;
vs all,f,rest,rr;
multiset<string>ff,r;
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
inline vs query(ll l,ll r)
{
	vs v;
	string s;
	if(l>r)
	{
		return vs();
	}
	cout<<"? "<<l<<" "<<r<<endl;
	for(register int i=1;i<=(r-l+1)*(r-l+2)/2;i++)
	{
		cin>>s,sort(s.begin(),s.end()),v.push_back(s);
	}
	sort(v.begin(),v.end());
	return v;
}
int main()
{
	cin>>cnt,all=query(1,cnt),f=query(1,1),rest=query(2,cnt);
	for(auto &x:rest)
	{
		r.insert(x);
	}
	ff.insert(f[0]);
	for(auto &x:all)
	{
		if(ff.find(x)!=ff.end())
		{
			ff.erase(ff.find(x));
		}
		else
		{
			if(r.find(x)!=r.end())
			{
				r.erase(r.find(x));
			}
			else
			{
				r.insert(x);
			}
		}
	}
	rr.push_back(f[0]);
	for(auto &x:r)
	{
		rr.push_back(x);
	}
	sort(rr.begin(),rr.end(),[&](const string &a, const string &b) {
    	return a.length()<b.length();
  	});
  	for(register int i=0;i<cnt;i++)
  	{		
    if (!i) {
      res += rr[i][0];
      continue;
    }
    else {
      multiset<char> c;
      for (auto &x: rr[i])
        c.insert(x);
      for (auto &x: rr[i - 1])
        c.erase(c.find(x));
      res += *c.begin();
    }
  }
  cout<<"! "<<res<<endl;
}