#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{ios::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin>>t;
 string s;
 while(t--)
    {cin>>s;
     int currx=0;
     int curry=0;
     vector<pair<int,int>> v;
     for(int i=0;i<s.size();i++)
        {if(s[i]=='L'){currx--;}
         if(s[i]=='R'){currx++;}
         if(s[i]=='U'){curry++;}
         if(s[i]=='D'){curry--;}
         v.push_back(make_pair(currx,curry));
        }
    int poss=0;
    pair<int,int> ans;
     for(auto x:v)
        {int n=x.first;
         int m=x.second;
         int currx=0;int curry=0;
        for(int i=0;i<s.size();i++)
        {if(s[i]=='L' && ((currx-1)!=n || curry!=m)){currx--;}
         if(s[i]=='R' && ((currx+1)!=n || curry!=m)){currx++;}
         if(s[i]=='U' && ((currx)!=n || (curry+1)!=m)){curry++;}
         if(s[i]=='D' && ((currx)!=n || (curry-1)!=m)){curry--;}
         //v.push_back(make_pair(currx,curry));
        }
        if(currx==0 && curry==0){poss=1;ans.first=n;ans.second=m;break;}
        }
    if(poss==0){cout<<"0 0\n";}
    else{cout<<ans.first<<" "<<ans.second<<"\n";}
    }
}