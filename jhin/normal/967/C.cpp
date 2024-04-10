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

int n,k,m,cl,ce,v,fi,q,sum,ans,x1,x2,y1,y2;vector<int> el,st;
int main()
{
ios_base::sync_with_stdio(false);

   cin>>n>>m>>cl>>ce>>v;
   for(int i=0;i<cl;i++)cin>>k,st.push_back(k);
   for(int i=0;i<ce;i++)cin>>k,el.push_back(k);
   sort(el.begin(),el.end());sort(st.begin(),st.end());
   cin>>q;
   for(int i=0;i<q;i++)
   {
       cin>>x1>>y1>>x2>>y2;
       int ans1=1e9,ans2=1e9,ans3=1e9,ans4=1e9;
       if(x1==x2){cout<<abs(y1-y2)<<endl;continue;}
       if(el.size()==1){ans1=abs(y1-el[0])+abs(x1-x2)/v+abs(el[0]-y2);if(abs(x1-x2)%v)ans1++;}
       else if(!el.empty())
       {
           auto it=lower_bound(el.begin(),el.end(),y1);

           if(it==el.end())
           {
               it--;ans1=abs(y1-*it)+abs(x1-x2)/v+abs(*it-y2);if(abs(x1-x2)%v)ans1++;}

           else
           {  ans1=abs(y1-*it)+abs(x1-x2)/v+abs(*it-y2);if(abs(x1-x2)%v)ans1++;
              if(it!=el.begin())
            {it--;ans2=abs(y1-*it)+abs(x1-x2)/v+abs(*it-y2);if(abs(x1-x2)%v)ans2++;}
           }
       }

        if(st.size()==1){ans3=abs(y1-st[0])+abs(x1-x2)+abs(st[0]-y2);}
        else if(!st.empty())
        {
            auto it=lower_bound(st.begin(),st.end(),y1);

           if(it==st.end())
           {
               it--;ans3=abs(y1-*it)+abs(x1-x2)+abs(*it-y2);}

           else
           { ans3=abs(y1-*it)+abs(x1-x2)+abs(*it-y2);
              if(it!=st.begin())
            {it--;ans4=abs(y1-*it)+abs(x1-x2)+abs(*it-y2);}
           }
        }
        
        cout<<min(min(ans1,ans2),min(ans3,ans4))<<endl;
       }

    return 0;
}