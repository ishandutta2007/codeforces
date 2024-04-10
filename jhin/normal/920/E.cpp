// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;


#define ll long long
const int mod=1e9+7;
vector<int> p;
string s,s2;
ll x,y,sum,cnt1,cnt2,k;
int ho,se,mi,z,n,m;
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
bool vis[200003];
set <int> v[200003];
set <int> nums;
void dfs(int x)
{

    auto it=nums.lower_bound(x);//cout<<"X "<<x<<endl;
    nums.erase(it);cnt1++;
auto i=nums.begin();i++;//if(x==4)cout<<"i4 "<<*i<<endl;
   for(i;i!=nums.end();)
   {
        int ii=*i;i--;
       if(*v[x].lower_bound(ii)!=ii)
        dfs(ii);
        else i++;auto j=nums.lower_bound(*i);
        if(*i==*j) i++;
        else i=j;//cout<<"I "<<*i<<" ";
       // if(i==nums.end())cout<<"khraaa"<<endl;cout<<cnt1<<" "<<*i<<endl;for(auto kh=nums.begin();kh!=nums.end();kh++)cout<<*kh<<" ";cout<<endl;if(cnt1>3){return;}
   }
}

vector<int> ans;


int main()
{
ios_base::sync_with_stdio(false);

    cin>>n>>m;
    for(int i=0;i<m;i++)
    {cin>>x>>y;v[x].insert(y);v[y].insert(x);}
    for(int i=0;i<=n;i++)nums.insert(i);
    auto it=nums.begin();it++;
    for(it;it!=nums.end();)
    {   cnt1=0;int ii=*it;it--;
            dfs(ii);
        if(cnt1!=0)ans.push_back(cnt1);it++;//cout<<*it<<"  ";
    }
    sort(ans.begin(),ans.end());
     z=ans.size();
    cout<<z<<endl;
    for(int i=0;i<z;i++)
            cout<<ans[i]<<" ";


    return 0;
}