#include <iostream>
#include <cmath>
using namespace std;

int main()
{ios::sync_with_stdio(0);
   long long m,b;
cin>>m>>b;
/*long long x=(m*b)/2;
long long  x1 =x-1;
long long x2 =x+1;
long long y= (-1*(x+0.0)/m+0.0)+b;
long long y1= (-1*(x1+0.0)/m+0.0)+b;
long long y2= (-1*(x2+0.0)/m+0.0)+b;
//x= int(x);
//cout<<x<<" "<<y<<<<" "<<ans<<endl<<x1<<" "<<y1<<endl<<x2<<" "<<y2<<ans2<<endl;
long long ans1= (y1*(y1+1)/2)*(x1+1)+(x1*(x1+1)/2)*(y1+1);
long long ans2= (y2*(y2+1)/2)*(x2+1)+(x2*(x2+1)/2)*(y2+1);

long long ans= (y*(y+1)/2)*(x+1)+(x*(x+1)/2)*(y+1);
//cout<<ans<<" "<<ans2<<" "<<ans1<<endl;
cout<<max(ans1,max(ans2,ans));
//cout<<x<<" "<<y<<" "<<
//ans<<endl<<x1<<" "<<y1<<
//" "<<ans1<<endl<<x2<<" "<<y2<<" "<<ans2<<endl;*/
long long l=0;
for(long long i=0;i<=b;i++)

{long long y=i;
long long  x=(-1.0*y+b)*m;
long long ans= (y*(y+1)/2)*(x+1)+(x*(x+1)/2)*(y+1);

    l=max(l,ans);
}
cout<<l;
    return 0;
}