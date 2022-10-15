#include<bits/stdc++.h>
#define int long long
using namespace std;
map<int,int> z;
int n;
int f(int m)
  {//can m be the number of screens
      if(m==0){return 0;}
   int s=(n+m-1)/(m);
   int num0=m*s-(n);
   int num1=s-num0;
   for(auto x:z)
    {int ok=x.second;
   int si=(ok+s-1)/(s);
   int num0i=si*s-(ok);
   int num1i=si-num0i;
   num0-=num0i;
   num1-=num1i;
    }
    if(num0>=0 && num1>=0){return 1;}
    return 0;
  }
int bsearch(int l,int r)
{int m=(l+r)/2;
cout<<l<<" "<<r<<"\n";
if(f(m))
    {if(f(m-1)==0){return m;}
    return bsearch(l,m-1);
    }
    return bsearch(m+1,r);
}
int32_t main()
{ios::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin>>t;
 while(t--)
    {z.clear();
     map<int,int> ol;
     cin>>n;
     int dum;
     for(int i=0;i<n;i++)
        {cin>>dum;z[dum]++;
        }
    map<int,int> op;
    for(auto x:z)
        {int y=x.second;
         for(int j=y+1;j>=1;j--)
            {int c=(y+j-1)/j;
             c=c*(j-1);
             if(c<=y)
                {ol[j]++;//cout<<j<<" ";
                 op[j]+=((y+j-1)/j);
                }
            }
        //cout<<"\n";
        }
        //cout<<"done\n";
    int mina=1000000000000;
    for(auto x:ol)
        {if(x.second==z.size()){mina=min(mina,op[x.first]);}
        }
    //cout<<ans<<"\n";
    cout<<mina<<"\n";
    }
}