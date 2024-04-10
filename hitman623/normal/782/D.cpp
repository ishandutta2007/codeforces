#include <bits/stdc++.h>
#define pb push_back
using namespace std;
struct s
{
    string a,b;
};
map < string , long > mp,check;
long visi[1003]={0};
int main()
{
   long n,i,target,fl,j;
   string name[1003];
   s c[1003];
   char f[21],l[21];
   cin>>n;
   for(i=0;i<n;++i)
   {
       cin>>f>>l;
       c[i].a.pb(f[0]);
       c[i].a.pb(f[1]);
       c[i].a.pb(f[2]);
       c[i].b=c[i].a;
       c[i].b[2]=l[0];
       mp[c[i].a]++;
   }
   for(i=0;i<n;++i)
   {
       fl=0;target=-1;
       for(j=0;j<n;++j)
       {
           if(visi[j]) continue;
           if(mp[c[j].a]>1)
           {
               if(check[c[j].b]==1) {cout<<"NO";exit(0);}
               else { name[j]=c[j].b;visi[j]=1;check[name[j]]=1;fl=1;}
           }
           else
           {
               if(check[c[j].a]==1 && check[c[j].b]==1) {cout<<"NO";exit(0);}
               if(check[c[j].a]==1) {name[j]=c[j].b;visi[j]=1;check[name[j]]=1;fl=1;}
               else if(check[c[j].b]==1) {name[j]=c[j].a;visi[j]=1;check[name[j]]=1;fl=1;}
               else target=j;
           }
       }
       if(fl==0)
        {
            if(target==-1) break;
            name[target]=c[target].a;visi[target]=1;check[name[target]]=1;
        }
   }
   cout<<"YES"<<endl;
   for(i=0;i<n;++i)
   cout<<name[i]<<endl;
   return 0;
}