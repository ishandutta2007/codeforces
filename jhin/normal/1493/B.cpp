#include <bits/stdc++.h>

        using namespace std;




        const int mod=998244353;
        vector<long long> p;


        int ho,mi,se,ho1,mi1;
        void fix_time()
        {   if(se>59)mi+=se/60,se=se%60;if(se<0)se+=60,mi--;
            if(mi>59)ho+=mi/60,mi=mi%60;if(mi<0)mi+=60,ho--;
            if(ho<0)ho+=24;if(ho>=24)ho-=24;
        }
        unsigned long long my_pow(int x,int y)
        {  unsigned  long long num=1;
            for(unsigned long long i=x;y>0;i=(i*i),y>>=1)
                if(y&1){num=(num%mod*i%mod)%mod;}
                    return num;
        }

        bool prime[10000001],prime2[1000001];
        void sieve(){
        for(int i=2;i<=10000000;i+=2)
        prime[i]=false,prime[i-1]=true;
        prime[2]=true;
        for(int i=3;i*i<=10000000;i+=2)
            if(prime[i])
                for(int j=i*i;j<=10000000;j+=2*i)
                    prime[j]=false;
                    }
        vector<long long>vv,vv1;

        long long gcd(long long a , long long b)
        {
          if(b==0) return a;
                   a%=b;
            return gcd(b,a);
        }
       long long cnt=0;
    void pfact(long long x)
    {   if(x%2==0){p.push_back(2);while(x%2==0)x/=2,cnt++;vv.push_back(cnt);}
    for(long long i=3;i*i<=x;i+=2)
    if(x%i==0){cnt=0;p.push_back(i);while(x%i==0)x/=i,cnt++;vv.push_back(cnt);}
    if(x>1)p.push_back(x),cnt++,vv.push_back(1);
    }
        long long m,n,x,y,z,k,mn=1e9,mx,ans,a[500003],b[500003],c[500003],d[500003];bool yes1,yes2;vector<long long>v;char ch;



        string s;



        int t,x1,y1,z1;
        bool yes;

int xx,yy;
void putn(string stri)
{
    int fx=int(stri[0]-'0');
    fx*=10;
    fx+=int(stri[1]-'0');
    int sx=int(stri[3]-'0');
    sx*=10;
    sx+=int(stri[4]-'0');
    xx=fx;yy=sx;
    //cout<<xx<<" "<<yy<<endl;
}
string rev(string str)
{
    string reve="";
    if(str[4]=='0'||str[4]=='1'||str[4]=='8')reve+=str[4];
    else if(str[4]=='2')reve+='5';
    else if(str[4]=='5')reve+='2';
    else return "error";
    if(str[3]=='0'||str[3]=='1'||str[3]=='8')reve+=str[3];
    else if(str[3]=='2')reve+='5';
    else if(str[3]=='5')reve+='2';
    else return "error";
    reve+=':';
    if(str[1]=='0'||str[1]=='1'||str[1]=='8')reve+=str[1];
    else if(str[1]=='2')reve+='5';
    else if(str[1]=='5')reve+='2';
    else return "error";
    if(str[0]=='0'||str[0]=='1'||str[0]=='8')reve+=str[0];
    else if(str[0]=='2')reve+='5';
    else if(str[0]=='5')reve+='2';
    else return "error";
    putn(reve);
    if(xx>=x||yy>=y)return "error";
    return reve;

}

string nexmin(string tim)
{
   putn(tim);
   yy++;
   if(yy==y)xx++,yy=0;
   if(xx==x)xx=0;
   string newtim="";
   if(xx==0)newtim+="00";
   else{


   string hor="";
   hor+='0'+(xx/10);
   xx%=10;
   hor+='0'+(xx);
   newtim+=hor;}
   newtim+=':';
   if(yy==0)newtim+="00";
   else{

   string minu="";
   minu+='0'+(yy/10);
   yy%=10;
   minu+='0'+(yy);

   newtim+=minu;}
   return newtim;


}


        int main()
        {

        ios_base::sync_with_stdio(false);




       cin>>t;


       while(t--)
       {
          cin>>x>>y;
          cin>>s;

          while(1)
          {
              string re=rev(s);
              //cout<<xx<<" "<<yy<<endl;
              if(re!="error")
              {
                  cout<<s<<endl;
                  break;
              }
              else s=nexmin(s);
              //cout<<s<<endl;
          }



       }

        return 0;
        }