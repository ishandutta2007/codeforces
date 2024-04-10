#include <bits/stdc++.h>

using namespace std;
vector<int> a,b;
int v;
bool deer(int x,int y,int z)
{v=0;
for(int i=x;i<=y;i++){if(a[i]<a[z]){v++;}}
   // cout<<v<<" "<<z<<endl;
    if(v==z-x)return true;
    return false;

}
int main()
{//ios::sync_with_stdio(0);
    int x,n,m,y,z;
 scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
  {
     scanf("%d",&x);
      a.push_back(x);
  }
  for(int i=0;i<m;i++)
  {
      scanf("%d%d%d",&x,&y,&z);
//      deer(x-1,y-1,z-1)

     // for(int i=0;i<n;i++){cout<<b[i]<<" ";}
      if(deer(x-1,y-1,z-1)){printf( "Yes\n");}else{printf( "No\n");}
  }

    return 0;
}