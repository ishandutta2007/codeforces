#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;
int x[10]={1,0,1,2,0,1,2,0,1,2};
int y[10]={3,0,0,0,1,1,1,2,2,2};

int ans[10]={0,1,2,3,4,5,6,7,8,9};
int main() 
{ 

int n;
cin>>n;
char s[11];
cin>>s[0];
for(int i=1;i<n;i++)
{
/*for(int p=0;p<10;p++)cout<<ans[p]<<" ";
cout<<endl;*/
cin>>s[i];
int l;
if(s[i]-'0'==0)l=1;else l=(s[i]-'0'-1)%3;
int v;
if(s[i]-'0'==0)v=3;else v=(s[i]-'0'-1)/3;
int l2;
if(s[i-1]-'0'==0)l2=1;else l2=(s[i-1]-'0'-1)%3;
int v2;
if(s[i-1]-'0'==0)v2=3;else v2=(s[i-1]-'0'-1)/3;
l-=l2;
v-=v2;
//cout<<l<<" "<<v<<endl;

for(int j=0;j<10;j++)
{
if(ans[j]==-1)continue;
int d1=x[ans[j]]+l;
int d2=y[ans[j]]+v;
if(d1<0||d1>2||d2<0||d2>3){ans[j]=-1;continue;}
if(d2==3&&(d1!=1)){ans[j]=-1;continue;}
if(d2==3&&d1==1){ans[j]=0;continue;}
//cout<<d1<<" "<<d2<<endl;
ans[j]=d2*3+d1+1;

}


}
int k=0;
for(int i=0;i<10;i++)
if(ans[i]!=-1)k++;
if(k==1)cout<<"YES";else cout<<"NO";
return 0 ;}