#include<bits/stdc++.h>
#define int long long
using namespace std;
int sorted[200005];
int n,m,timer;
int a[200005];
int f(int x)
{//is possible
    if(x>n){return 0;}
    int d=sorted[x-1];
    int counter=0;
    int taken=0;
    int lasttime=0;
    for(int i=0;i<n;i++)
        {
            if(a[i]<=d)
                {//cout<<counter<<" "<<timer<<"\n";
                    if(counter+a[i]>timer){break;}
                    taken++;
                    lasttime+=a[i];
                    counter+=a[i];
                    if(taken%m==0)
                        {
                            counter+=lasttime;
                            lasttime=0;
                        }
                }
        }
    if(taken>=x){return 1;}
    return 0;
}
int bsearch(int l,int r)
{//first not possible
    while(l<r)
        {int m=(l+r)/2;
         if(f(m))
            {l=m+1;
            }
         else
            {r=m;
            }
        }
    return l-1;
}
int32_t main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;
while(t--)
    {cin>>n>>m>>timer;
     for(int i=0;i<n;i++){cin>>a[i];sorted[i]=a[i];}
     sort(sorted,sorted+n);
     //sort(a,a+n);
     int z=bsearch(1,n+5);
     if(z>=1)
        {cout<<z<<" "<<sorted[z-1]<<"\n";
        }
     else
        {cout<<z<<" "<<timer<<"\n";
        }
    //cout<<f(5)<<"\n";
    }
}