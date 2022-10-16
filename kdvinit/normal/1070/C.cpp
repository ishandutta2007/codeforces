#include<bits/stdc++.h>
#define int long long
using namespace std;

struct segtree
{
 vector<int> v;
    void init(int n)
    {int curr=1;
    while(curr<n){curr=curr*2;}
    for(int i=0;i<2*curr;i++){v.push_back(0);}
    }
void update(int lx,int rx,int curr,int i,int z)
{
    if(rx-lx==1){v[curr]=z;return;}
    int m=(lx+rx)/2;
    if(i<m)
        {update(lx,m,2*curr+1,i,z);
        }
    else
        {update(m,rx,2*curr+2,i,z);
        }
    v[curr]=v[2*curr+1]+v[2*curr+2];
}

int getsum(int l,int r,int lx,int rx,int curr)
{
    if(lx>=l && rx<=r){return v[curr];}
    if(lx>=r || rx<=l){return 0;}
    int m=(lx+rx)/2;
    return getsum(l,r,lx,m,2*curr+1)+getsum(l,r,m,rx,2*curr+2);
}

int minimum_till(int lx,int rx,int curr,int k)
{
    if(rx-lx==1){return lx;}
    int num1=v[2*curr+1];
    //cout<<num1<<"\n";
    int m=(lx+rx)/2;
    if(k<=num1 || v[2*curr+2]==0)
        {
            return minimum_till(lx,m,2*curr+1,k);
        }
    else
        {
            return minimum_till(m,rx,2*curr+2,k-num1);
        }
}
};
int32_t main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n,k,m;
cin>>n>>k>>m;
vector<int> v[n+1];
vector<tuple<int,int,int,int>> op;//price,core,price*core i
for(int i=0;i<m;i++)
    {int l,r,c,p;
     cin>>l>>r>>c>>p;
     l--;r--;
     v[l].push_back(i+1);
     v[r+1].push_back(-(i+1));
     op.push_back(make_tuple(p,c,p*c,i));
    }
sort(op.begin(),op.end());
int occurs[m];
for(int i=0;i<m;i++)
    {occurs[(get<3>(op[i]))]=i;
    }

int ans=0;
struct segtree st1,st2;//cores,price*core
st1.init(m);st2.init(m);
for(int i=0;i<n;i++)
    {
        for(auto x:v[i])
            {if(x>0)
                {int ind=x-1;
                 int lop=occurs[ind];
                 //cout<<lop<<"\n";
                 int val=(get<1>)(op[lop]);
                 int poslo=(get<2>)(op[lop]);
                 //cout<<val<<" "<<poslo<<"\n";
                 st1.update(0,m,0,lop,val);
                 st2.update(0,m,0,lop,poslo);
                }
            else
                {
                    int ind=-x;
                    ind--;
                    int lop=occurs[ind];
                    st1.update(0,m,0,lop,0);
                    st2.update(0,m,0,lop,0);
                }
            }
        int pok=st1.minimum_till(0,m,0,k);
        int zf=st1.getsum(0,pok,0,m,0);
        int opop=k-zf;
        ans+=st2.getsum(0,pok,0,m,0);
        //cout<<ans<<"\n";
        if(st2.getsum(0,m,0,m,0))
        {int core=(get<1>)(op[pok]);
        int price=(get<0>)(op[pok]);
        ans+=(min(opop,core)*price);}
        //cout<<ans<<" "<<pok<<"\n";
    }
cout<<ans<<"\n";
}