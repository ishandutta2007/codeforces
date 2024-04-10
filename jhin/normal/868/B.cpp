#include <iostream>

using namespace std;
int h,m,s,t1,t2,m1,m2,b,f;bool ans;
void mb(int x){if(x==0)b++;}void mf(int x){if(x==60)f++;}
int ho(int i){if(i==60)return 0;return i/5;}
bool canb(int x){

    if(ho(x-1)!=ho(m)&&ho(x-1)!=ho(s)&&ho(x-1)!=h) return true;
    return false;
}
bool canf(int x){

    if(ho(x)!=ho(m)&&ho(x)!=ho(s)&&ho(x)!=h){
        if(ho(x+5)==h&&s==0&&m==0)return false;
    return true;}
    return false;
}
int main()
{
    cin>>h>>m>>s>>t1>>t2;
    if(t1==12)t1=0;if(t2==12)t2=0;if(h==12)h=0;
    m1=t1*5;m2=t2*5;
    for(int i=m1;f<2;i+=5)
    {mf(i);


        if(i==60)i=0;
if(i==m2){ans=true;break;}
        if(!canf(i)) break;

    }

    if(!ans)
      for(int i=m1;b<2;i-=5)
    {   mb(i);
    if(i==m2){ans=true;break;}

        if(i==0)i=60;

        if(!canb(i)) break;

    }

    if(ans)cout<<"YES";else cout<<"NO";
    return 0;
}