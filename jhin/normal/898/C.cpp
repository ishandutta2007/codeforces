// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;


#define ll long long
const int mod=1e9+7;
vector<int> p;
string s,s2;
ll n,x,y,sum,cnt1,cnt2,m;
int ho,se,mi;
void fix_time()
{   if(se>59)se-=60,mi++;if(se<0)se+=60,mi--;
    if(mi>59)mi-=60,ho++;if(mi<0)mi+=60,ho--;
    if(ho<0)ho+=24;if(ho>23)ho-=24;
}
ll my_pow(int x,int y)
{    ll num=1;
    for(ll i=x;y>0;i=(i*i)%mod,y>>=1)
        if(y&1)num=((num%mod)*i)%mod;
    return num%mod;
}
void pfact(int x)
{   if(x%2==0){p.push_back(2);while(x%2==0)x/=2;}
    for(int i=3;i*i<=x;i+=2)
        if(x%i==0){p.push_back(i);while(x%i==0)x/=i;}
    if(x>1)p.push_back(x);
}

map<string,vector<string>> phone1;
map<string,vector<int>> phone2;
int comp(string small,string big)
{
    bool swaped=false;
    if(small.size()>big.size())swap(small,big),swaped=true;

    for(int i=small.size()-1,j=big.size()-1;i>=0;i--,j--)
        if(small[i]!=big[j])
        return 0;
        if(swaped)return 2;
        else return 1;
    }
#define f it->first
int main()
{
   ios_base::sync_with_stdio(false);
   cin>>n;
   for(int i=0;i<n;i++)
   {
       cin>>s>>m;
       for(int i=0;i<m;i++)
       cin>>s2,phone1[s].push_back(s2);
   }
   for(auto it=phone1.begin();it!=phone1.end();it++)
   {
       for(int i=0;i<phone1[f].size();i++)
        for(int j=i+1;j<phone1[f].size();j++){
            if(comp(phone1[f][j],phone1[f][i])==1)
                phone1[f].erase(phone1[f].begin()+j),j--;
            else if(comp(phone1[f][j],phone1[f][i])==2)
                {phone1[f].erase(phone1[f].begin()+i);i--;break;}
            }
   }
cout<<phone1.size()<<endl;
   for(auto it=phone1.begin();it!=phone1.end();it++)
    {cout<<f<<" "<<phone1[f].size()<<" ";
   for(int i=0;i<phone1[f].size();i++)
   cout<<phone1[f][i]<<" ";cout<<endl;
    }
    return 0;
}