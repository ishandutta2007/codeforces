#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=400009;
int n,q;
int fr[N],a[N],b[N];
set<pair<int,int> >st;
int cal(int x)
{
    set<pair<int,int> >::iterator it=st.lower_bound(make_pair(x+1,0));
    if(it==st.begin())return 0;
    it--;
    if(x>=((*it).first)&&(x<=((*it).second)))return 1;
    return 0;
}
void dec(int x)
{
  int u=cal(x);
  if(u){
    set<pair<int,int> >::iterator it=st.lower_bound({x+1,0});
    it--;
    int str=(*it).first,en=(*it).second;
    st.erase(it);
    if(x>str)st.insert({str,x-1});
    if(en>x)st.insert({x+1,en});
    return;
  }
 set<pair<int,int> >::iterator it=st.lower_bound({x+1,0});
int str=(*it).first,en=(*it).second;
st.erase(it);
if(en>str)st.insert({str+1,en});
it=st.lower_bound({x,0});
if(it==st.begin())
{
    st.insert({x,str-1});
    return;
}
it--;
if((*it).second==x-1)
{
    int d=(*it).first;
    st.erase(it);
    st.insert({d,str-1});
    return;
}
   st.insert({x,str-1});
}
void inc(int x)
{
  int u=cal(x);
  if(u==0){
    set<pair<int,int> >::iterator it=st.lower_bound({x+1,0});
    int str=x,en=x;
      if((it!=st.end() )&& (*it).first==x+1){en=(*it).second;st.erase(it);}
    it=st.lower_bound({x+1,0});
    if(it!=st.begin())
    {
        it--;
        if((*it).second==x-1){str=(*it).first;st.erase(it);}
    }
    st.insert({str,en});

    return;
  }
 set<pair<int,int> >::iterator it=st.lower_bound({x+1,0});
it--;
int str=(*it).first,en=(*it).second;
st.erase(it);
if(str<x)st.insert({str,x-1});
x=en+1;
   it=st.lower_bound({x+1,0});
     str=x,en=x;
      if((it!=st.end() )&& (*it).first==x+1){en=(*it).second;st.erase(it);}
   it=st.lower_bound({x+1,0});
    if(it!=st.begin())
    {
        it--;
        if((*it).second==x-1){str=(*it).first;st.erase(it);}
    }
    st.insert({str,en});

    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        fr[a[i]]++;
    }
    for(int i=1;i<300009;i++)
    {b[i]+=fr[i];
    b[i+1]=b[i]/2;}
    int i=1;
    while(i<300000)
    {
        if((b[i]%2)==0){i++;continue;}
        int j=i;
        while(b[j]%2)j++;
        st.insert({i,j-1});
        i=j;
    }
    while(q--)
    {
        int k,l;
        cin>>k>>l;
        inc(l);
        dec(a[k]);
        a[k]=l;
        set<pair<int,int> >::iterator it=st.end();
        it--;
        int res=(*it).second;
        cout<<res<<endl;
    }


    return 0;
}