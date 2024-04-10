#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int h,m;
int rv[12];
bool ch(int a,int b)
{
    int u=a/10,v=a%10;
    int w=b/10,z=b%10;
    if(rv[u]==-1||rv[v]==-1||rv[w]==-1||rv[z]==-1)return false;
   u=rv[u];
   v=rv[v];
   w=rv[w];
   z=rv[z];
   int mnt=u+v*10,hr=z*10+w;
   if(mnt>=m||hr>=h)return false;
   return true;
}
int main()
{   int n,k,t;
    rv[0]=0;
    rv[1]=1;
    rv[2]=5;
    rv[3]=-1;
    rv[4]=-1;
    rv[5]=2;
    rv[6]=-1;
    rv[7]=-1;
    rv[8]=8;
    rv[9]=-1;

    cin>>t;

    while(t--)
    {
        int a,b;
        cin>>h>>m;
        scanf("%d:%d",&a,&b);
        while(!ch(a,b))
        {
            b++;
            if(b==m){b=0;a++;}
            if(a==h)a=0;
        }
        cout<<a/10<<a%10<<":"<<b/10<<b%10<<endl;

    }
    return 0;
}