#include <bits/stdc++.h>

using namespace std;
long long n,s,a,b,x,c,p,c1,c2,c3,ans1,ans2,ans3,k;
long long sum;

int main()
{
    cin>>n>>s;
    vector<pair<pair<long long,long long>,long long>> s1,s2;
    vector<pair<long long,long long>> s3;
    for(int i=0;i<n;i++)
    {
        cin>>x>>a>>b;p+=x;
        if(a==b)s3.push_back(make_pair(b,x)),sum+=b*x,ans3+=b*x,c3+=x;
        if(a>b) s1.push_back(make_pair(make_pair(a-b,x),b)),c1+=x,sum+=a*x;
        if(a<b) s2.push_back(make_pair(make_pair(b-a,x),a)),c2+=x,sum+=b*x;
    }
    p=(p+s-1)/s; sort(s1.begin(),s1.end());sort(s2.begin(),s2.end());sort(s3.begin(),s3.end());
  // for(int i=0;i<s1.size();i++){cout<<s1[i].first.first+s1[i].second<<" "<<s1[i].first.second<<" "<<s1[i].second<<" ";}cout<<endl;
   //for(int i=0;i<s2.size();i++){cout<<s2[i].first.first+s2[i].second<<" "<<s2[i].first.second<<" "<<s2[i].second<<" ";}cout<<endl;

    if(c1%s+c2%s+c3>s)cout<<sum;
    else
    { sum=0;
      k=c1/s;
      for(long long i=k*s,j=s1.size()-1;i>0;j--)
      {
          if(i>=s1[j].first.second){ i-=s1[j].first.second;sum+=(s1[j].first.first+s1[j].second)*s1[j].first.second;s1[j].second=0;}
                               else {s1[j].first.second-=i;sum+=(s1[j].first.first+s1[j].second)*i;i=0;}
      }
      k=c2/s;
      for(long long i=k*s,j=s2.size()-1;i>0;j--)
      {
          if(i>=s2[j].first.second){ i-=s2[j].first.second;sum+=(s2[j].first.first+s2[j].second)*s2[j].first.second;s2[j].second=0;}
                               else {s2[j].first.second-=i;sum+=(s2[j].first.first+s2[j].second)*i;i=0;}
      }
      for(int i=0,j=c1%s;j>0;i++){j-=s1[i].first.second;
      ans1+=(s1[i].first.first+s1[i].second)*s1[i].first.second;
      ans2+=s1[i].second*s1[i].first.second;

      }
      for(int i=0,j=c2%s;j>0;i++){j-=s2[i].first.second;
      ans2+=(s2[i].first.first+s2[i].second)*s2[i].first.second;
      ans1+=s2[i].second*s2[i].first.second;

      }
      sum+=ans3;
      if(ans1>ans2)sum+=ans1;else sum+=ans2;
      cout<<sum;
    }





    return 0;
}