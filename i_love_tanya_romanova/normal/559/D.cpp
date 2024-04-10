/*
*/
 
//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>  
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <ctime> 

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512
#define maxlen (1<<20)
#define alphabet 256
#define root asdfasdfadsfassdg

using namespace std;

int n;
int x[1<<20],y[1<<20];
long long area,border;

int gcd(int a, int b)
{
    if (a<0)
        a=-a;
    if (b<0)
        b=-b;
//      cout<<"#"<<a<<" "<<b<<endl;
    while (a&&b)a>b?a%=b:b%=a;
    return a+b;
}

long long pick(long long area,long long border)
{
    long long i;
//  2*A=2*i+b-2;
//  -2i=-2A+b-2;
    i=-area+border-2;
    return -i/2;
}

long double pw(long long a,long long b)
{
    if (b==0)
        return 1;
    if (b%2)    
        return a*pw(a,b-1);
    return pw(a*a,b/2);
}

long long ttarea,ttborder;
int G[1<<20];

int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    x[i]=a;
    y[i]=b;
/// cin>>x[i]>>y[i];
}

area=0;
border=0;

x[0]=x[n];
y[0]=y[n];

for (int i=1;i<=n;i++)
{
    border+=gcd(x[i]-x[i-1],y[i]-y[i-1]);
    area+=1ll*x[i]*y[i-1]-1ll*x[i-1]*y[i];
}

//cout<<"@"<<endl;

if (area<0)
    area=-area;

//cout<<area<<"  "<<border<<endl;

long double total=pick(area,border);

//cout<<total<<endl;

long double WAYS=pow(2,n)-1-n-1ll*n*(n-1)/2;

for (int i=n+1;i<=n*2;i++)
    x[i]=x[i-n],
    y[i]=y[i-n];

for (int i=1;i<=n*2;i++)
    G[i]=gcd(x[i]-x[i-1],y[i]-y[i-1]);
    
for (int i=1;i<=n;i++)
{
    long long tarea=0;
    long long tborder=0;
    
    for (int j=i+1;j<i+n-1&&j<=i+93;j++)
    {
        long double prob;
        if (n<100)
        {
        prob=pow(2.0,n-(j-i)-1)-1;
        prob/=WAYS; 
        }
        else
        {
            prob=pow(0.5,(j-i+1));
        }
        
        tarea+=1ll*x[j-1]*y[j]-1ll*x[j]*y[j-1];
        tborder+=G[j];
        ttarea=tarea+1ll*x[j]*y[i]-1ll*x[i]*y[j];
        if (ttarea<0)
            ttarea=-ttarea;
        int val=gcd(x[j]-x[i],y[j]-y[i]);
        ttborder=tborder+val;
        if (j==i+1)
            continue;
//      cout<<i<<" "<<j<<" "<<ttarea<<"%"<<ttborder<<endl;
        long long inside=pick(ttarea,ttborder);
        total-=(inside+val-1)*prob;  
    }
}

cout.precision(10);
cout<<fixed<<total<<endl;

//cin.get();cin.get();
return 0;}