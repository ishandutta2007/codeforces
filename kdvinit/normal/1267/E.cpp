#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{ios::sync_with_stdio(0);
 cin.tie(0);
 int n,m;
 cin>>n>>m;
 int sumi[n];
 memset(sumi,0,sizeof(sumi));
 int arr[m][n];
 for(int i=0;i<m;i++)
    {for(int j=0;j<n;j++)
      {cin>>arr[i][j];
       sumi[j]+=arr[i][j];
      }
    }
int maxa=m+1;
vector<int> z;
for(int i=0;i<n-1;i++)
    {//make i greater than the rest
     vector<pair<int,int>> v;
     for(int j=0;j<m;j++)
        {v.push_back(make_pair(arr[j][n-1]-arr[j][i],j));
        }
     sort(v.begin(),v.end());
     reverse(v.begin(),v.end());
     int curr=sumi[i]-sumi[n-1];
     //cout<<curr<<"\n";
     if(curr>=0){maxa=0;break;}
     int ans=0;
     for(int j=0;j<m;j++)
        {curr+=v[j].first;
        if(curr>=0)
            {ans=j+1;break;
            }
        }
    if(ans<maxa)
        {maxa=ans;
         z.clear();
         for(int k=0;k<ans;k++)
            {z.push_back(v[k].second);
            }
        }
    }
cout<<maxa<<"\n";
for(auto x:z){cout<<x+1<<" ";}
}