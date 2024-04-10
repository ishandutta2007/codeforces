#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n,k,m,x,y,z;
int ans;
vector<int>a[2][2];
vector<pair<int,int> >f[2][2];
int id[2][2];
int main()
{
//ios::sync_with_stdio(0);
//cin>>n>>m>>k;
scanf("%d%d%d",&n,&m,&k);
for(int i=0;i<n;i++)
{

   // cin>>x>>y>>z;
   scanf("%d%d%d",&x,&y,&z);
    a[y][z].push_back(x);
    f[y][z].push_back({x,i+1});
}
for(int i=0;i<2;i++)
    for(int j=0;j<2;j++){sort(a[i][j].begin(),a[i][j].end());a[i][j].push_back(1000000);sort(f[i][j].begin(),f[i][j].end());}
int ans=-1,sum=0,u=0;
while(u<a[1][1].size())
{
    if(u>m){u++;continue;}
    int r=max(k-u,0);
    if(r>=a[1][0].size()||r>=a[0][1].size()){u++;continue;}

    if((u+2*r)>m){u++;continue;}
if(a[1][0].size()+a[0][1].size()+a[0][0].size()+u<m+3){u++;continue;}
break;
}
if(u>=a[1][1].size())
    {cout<<-1;
return 0;}
//cout<<u<<endl;
int r=max(k-u,0);
int s1=r,s2=r,s3=0;
while(u+s1+s2+s3<m)
{

    int d=min(min(a[1][0][s1],a[0][1][s2]),a[0][0][s3]);
    if(d>10000){cout<<-1;return 0;}
    if(d==a[1][0][s1]){s1++;continue;}
    if(d==a[0][1][s2]){s2++;continue;}
    if(d==a[0][0][s3]){s3++;continue;}
}
//cout<<s1<<" "<<s2<<" "<<s3<<endl;
for(int i=0;i<u;i++)
    sum+=a[1][1][i];
for(int i=0;i<s1;i++)
    sum+=a[1][0][i];
for(int i=0;i<s2;i++)
    sum+=a[0][1][i];
for(int i=0;i<s3;i++)
    sum+=a[0][0][i];

    //cout<<sum<<endl;
ans=sum;
int q1=s1,q2=s2,q3=s3,q4=u;
s1--;
s2--;
s3--;


//cout<<44<<" "<<sum<<endl;
while(u+1<a[1][1].size())
{

    sum+=a[1][1][u];
    u++;
  //  cout<<sum<<endl;
    if(s1==-1&&s2==-1&&s3==-1)break;
    int d=0,pp=0;
    if((s1!=-1)){d+=a[1][0][s1];pp++;s1--;}
    if((s2!=-1)){d+=a[0][1][s2];pp++;s2--;}
    if((s3!=-1)){d+=a[0][0][s3];pp++;s3--;}
    //cout<<d<<endl;
    sum-=d;
for(int i=0;i<pp-1;i++)
{

    int gg=min(min(a[1][0][s1+1],a[0][1][s2+1]),a[0][0][s3+1]);
    if(gg>10000){cout<<-1;return 0;}
    if(gg==a[1][0][s1+1]){sum+=a[1][0][s1+1];s1++;continue;}
    if(gg==a[0][1][s2+1]){sum+=a[0][1][s2+1];s2++;continue;}
    if(gg==a[0][0][s3+1]){sum+=a[0][0][s3+1];s3++;continue;}
}

    if(sum<ans)
{
    ans=sum;
    q4=u;
    q3=s3+1;
    q2=s2+1;
    q1=s1+1;
}
}
//cout<<ans<<endl;
printf("%d\n",ans);
for(int i=0;i<q4;i++)
    printf("%d " ,f[1][1][i].second);
for(int i=0;i<q3;i++)
   // cout<<f[0][0][i].second<<" ";
 printf("%d " ,f[0][0][i].second);
for(int i=0;i<q2;i++)
    //cout<<f[0][1][i].second<<" ";
 printf("%d " ,f[0][1][i].second);
for(int i=0;i<q1;i++)
    //cout<<f[1][0][i].second<<" ";
 printf("%d " ,f[1][0][i].second);
   return 0;
}