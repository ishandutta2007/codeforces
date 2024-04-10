#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <fstream>
#include <map>
#include <queue>
#include <algorithm>
#define y1 sgjkdf
using namespace std;
long q,n,arp[3000],s,ans,ar[2100][2100];
vector <long> pp;
void dfs(long a,long b)
{arp[a]=1;ans=max(ans,b);
 for (int i=1;i<=n;i++)
 if (ar[a][i]==1&&arp[i]==0)
 {dfs(i,b+1);
                            }
}
int main(){
   // freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);

cin>>n;

for (int i=1;i<=n;i++)
{cin>>q;
 if (q==-1)pp.push_back(i);
 else {ar[q][i]=1;
 ar[i][q]=1;}
}

for (int i=0;i<pp.size();i++)
{q=pp[i];
 s=0;
 dfs(q,1);
}
cout<<ans<<endl;
cin.get();cin.get();cin.get();
return 0;
}