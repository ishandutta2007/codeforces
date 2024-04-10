// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;



#define f for(int i=0;i<n;i++)
const int mod=1e9+7;
vector<int> p;


int ho,mi,se;
void fix_time()
{   if(se>59)mi+=se/60,se=se%60;if(se<0)se+=60,mi--;
    if(mi>59)ho+=mi/60,mi=mi%60;if(mi<0)mi+=60,ho--;
    if(ho<0)ho+=24;if(ho>24)ho-=24;
}
long long my_pow(int x,int y)
{    long long num=1;
    for(long long i=x;y>0;i=(i*i),y>>=1)
        if(y&1)num=(num*i);
    return num;
}

bool prime[2500001];
void sieve(){
    for(int i=2;i<=2250000;i+=2)
        prime[i]=false,prime[i-1]=true;
    prime[2]=true;
    for(int i=3;i<=1500;i+=2)
        if(prime[i])
            for(int j=i*i;j<=2250000;j+=2*i)
                prime[j]=false;
}
void pfact(int x)
{   if(x%2==0){p.push_back(2);while(x%2==0)x/=2;}
    for(int i=3;i*i<=x;i+=2)
        if(x%i==0){p.push_back(i);while(x%i==0)x/=i;}
    if(x>1)p.push_back(x);
}
long long gcd(long long a , long long b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
int m,x,n,y,z,k,zero,mx,mn=1e9,l,r,pos,t,a[300003];string s,s2;vector<int>v,v2;long long ans;



int main()
{
ios_base::sync_with_stdio(false);

cin>>n;
while(n--)
{
    cin>>s;int num=0,lo=0,up=0;
    for(int i=0;i<s.size();i++)
    {if(int(s[i])<65)num++;
    else if(int(s[i])<97)up++;
    else lo++;}
    if(num&&(!lo&&!up)){s[0]='a',s[1]='A';cout<<s<<endl;continue;}
    if(up&&(!lo&&!num)){s[0]='a',s[1]='7';cout<<s<<endl;continue;}
    if(lo&&(!up&&!num)){s[0]='7',s[1]='A';cout<<s<<endl;continue;}
    for(int i=0;i<s.size();i++)
    {
        if(!num){if(lo>1&&int(s[i])>96){s[i]='7';break;}if(up>1&&int(s[i])<97){s[i]='7';break;}}
        if(!lo){if(num>1&&int(s[i])<65){s[i]='a';break;}if(up>1&&int(s[i])>64){s[i]='a';break;}}
        if(!up){if(lo>1&&int(s[i])>96){s[i]='A';break;}if(num>1&&int(s[i])<65){s[i]='A';break;}}
    }
    cout<<s<<endl;

}
return 0;
}