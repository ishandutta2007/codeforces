#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string go(int x)
{
    string ans="";
    if((x%9)>0)ans+=char('0'+(x%9));
    while(x>=9)
    {
        ans+='9';
        x-=9;

    }
    return ans;
}
string fuck(int x,int y)
{
    if(y>x+1)return"-1";
    if(y==x+1)
    {
        int d=min(8,x);
        x-=d;
        string ans=go(x);
        ans+=char(d+'0');
        return ans;
    }
    int d=x-y;
    if(d==0)return "-1";
    if(((d+1)%9)!=0)return "-1";
    d=(d+1)/9;
    string ans=go(x);
    int u=0;
    for(int i=ans.size()-1;i>=0;i--)if(ans[i]=='9')u++;else break;
    if(d>u)return "-1";
    int i=ans.size()-1-d;
    if(i==-1)return ans;
    if(ans[i]!='9')return ans;
    ans[i]=='8';
    i--;
    while(true)
    {
        if(i==-1){ans='1'+ans;break;}
        if(ans[i]!='9'){ans[i]++;break;}
        i--;
    }
    return ans;
}
string ans,tmp;
void rf()
{
   // cout<<tmp<<" "<<ans<<endl;
    if(tmp=="-1")return;
    if(ans=="-1"){ans=tmp;return;}
    if(tmp.size()<ans.size()){ans=tmp;return;}
    if(tmp.size()>ans.size())return;
    if(tmp<ans)ans=tmp;
}
int main()
{
    ios::sync_with_stdio(0);
    int t,n,k;
    cin>>t;
    while(t--)
    {
cin>>n>>k;

ans="-1";
for(int i=0;i+k<10;i++)
{

    int u=n;
    for(int j=i;j<i+k+1;j++)u-=j;

    if((u>=0)&&(u%(k+1)==0))
    {

        tmp=go((u/(k+1)));
//cout<<i<<" "<<tmp<<" "<<u<<endl;

        tmp=tmp+char(i+'0');

        rf();
    }

    }
    //cout<<ans<<endl;
int q=0;
for(int i=10-k;i<10;i++)
{
    q++;
    int r=(k+1-q);
    int u=n;
    for(int j=i;j<i+k+1;j++)u-=(j%10);
    if(u<=0)continue;
   // if(i==4)cout<<r<<" "<<q<<" "<<u<<endl;
    for(int j=0;j<=u;j++)
    {
        if((j%r)>0)continue;
        if(((u-j)%q)>0)continue;

        tmp=fuck((j/r),((u-j)/q));
        if(tmp=="0")tmp="";
        if(tmp=="-1")continue;
        tmp+=char(i+'0');
        rf();
    }

}
cout<<ans<<endl;
    }
    return 0;
}