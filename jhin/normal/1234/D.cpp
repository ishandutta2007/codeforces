#include <bits/stdc++.h>

using namespace std;

int BIT[100002][26], a[1000],t,n;string s;
void update(int x, char ch)
{
    int ind=int(ch-'a');
      for(; x <= 100001; x += x&-x)
        BIT[x][ind] ++;//,cout<<ind<<" "<<BIT[x][ind]<<" hh\n";
}
void delet(int x,char ch)
{
      int ind=int(ch-'a');
      for(; x <= 100001; x += x&-x)
        BIT[x][ind] --;
}
int sum[26],sum2[26];
void query(int x)
{
    int tmp=x;
     for(int i=0;i<26;i++)sum[i]=0;
     for(int i=0;i<26;i++){x=tmp;
     for(; x > 0; x -= x&-x)
        sum[i] += BIT[x][i];

}
}
void query2(int x)
{
    int tmp=x;
     for(int i=0;i<26;i++)sum2[i]=0;
     for(int i=0;i<26;i++){x=tmp;
     for(; x > 0; x -= x&-x)
        sum2[i] += BIT[x][i];

}
}
int k,xx,y;char c;
int main()
{
    cin>>s;
    for(int i=1;i<=s.size();i++)
    {
        update(i,s[i-1]);
        //for(int i=0;i<26;i++)cout<<sum[i]<<endl;
    }
     cin>>t;
     while(t--)
     {
      cin>>k;int ans=0;
      if(k==2)
      {
          cin>>xx>>y;
          query(xx-1);query2(y);
          int tmp[26]={0};
          for(int i=0;i<26;i++)if(sum2[i]-sum[i]>0)ans++;
          cout<<ans<<endl;
      }
      else
      {
          cin>>xx>>c;
          delet(xx,s[xx-1]);
          s[xx-1]=c;
          update(xx,c);
      }
     }
     return 0;
}