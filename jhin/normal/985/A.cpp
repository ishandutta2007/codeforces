// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define f for(int i=0;i<n;i++)
const int mod=1e9+7;
vector<int> p;


int ho,mi,se;
void fix_time()
{   if(se>59)mi+=se/60,se=se%60;if(se<0)se+=60,mi--;
    if(mi>59)ho+=mi/60,mi=mi%60;if(mi<0)mi+=60,ho--;
    //if(ho<0)ho+=24;if(ho>24)ho-=24;
}
int my_pow(int x,int y)
{    ll num=1;
    for(int i=x;y>0;i=(i*i),y>>=1)
        if(y&1)num=((num)*i);
    return num;
}

bool prime[1000001];
void sieve(){
    for(int i=2;i<=1000000;i+=2)
        prime[i]=false,prime[i-1]=true;
    prime[2]=true;
    for(int i=3;i<=1000;i+=2)
        if(prime[i])
            for(int j=i*i;j<=1000000;j+=2*i)
                prime[j]=false;
}
void pfact(int x)
{   if(x%2==0){p.push_back(2);while(x%2==0)x/=2;}
    for(int i=3;i*i<=x;i+=2)
        if(x%i==0){p.push_back(i);while(x%i==0)x/=i;}
    if(x>1)p.push_back(x);
}

vector<int> tree[100001],nodes,val(100002,1);
bool visited[100001];
int fthr[100001];
void addnodes(vector<int> a)
{    vector<int> tmp;
    for(int i=0;i<a.size();i++)
    {
        vector<int>ch=tree[a[i]];
        visited[a[i]]=true;
        for(int j=0;j<ch.size();j++)
        if(!visited[ch[j]])
        {nodes.push_back(ch[j]);
        tmp.push_back(ch[j]);
        fthr[ch[j]]=a[i];
        }
    }
    if(!tmp.empty())addnodes(tmp);
}
int n,x,y,ans1,ans2,a[100001];
void ne(vector<int> a)
{ vector<int>b=a;
 for(int i=0;i<a.size();i++) cout<<a[i]<<" "<<b[i];
}
int main()
{
ios_base::sync_with_stdio(false);

cin>>n;n=n/2;
for(int i=0;i<n;i++)cin>>a[i];
sort(a,a+n);
for(int i=0,j=1;i<n;i++,j+=2){ans1+=abs(a[i]-j);ans2+=abs(a[i]-(j+1));}
cout<<min(ans1,ans2);

return 0;
}