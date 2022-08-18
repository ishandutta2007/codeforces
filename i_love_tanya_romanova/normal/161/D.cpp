#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define INF 1000000000
#define eps 1e-9
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
long k,a,b,n,arp[200000],sz[51000][550],q;
vector <long> v[51000];
long long ans,qq,w;
void dfs(long a)
{
    long q; arp[a]=1;
     sz[a][0]=1;
     for (int i=0;i<v[a].size();i++)
     {q=v[a][i];if (arp[q]==0){dfs(q);
     for (int j=1;j<k;j++){
     ans+=sz[q][j-1]*(sz[a][k-j]);
    //cout<<j<<" "<<sz[q][j-1]<<" "<<(sz[i][k-j])<<endl;
    }
     ans+=sz[q][k-1];
     
     for (int j=1;j<=500;j++)sz[a][j]+=sz[q][j-1];}}
}

int main(){
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
cin>>n>>k;
for (int i=1;i<n;i++)
{
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
}

dfs(1);
/*for (int i=1;i<=n;i++)
{for (int j=0;j<=k;j++)
cout<<sz[i][j]<<" ";
cout<<endl;
}*/

//for (int i=1;i<=n;i++)
//{
//    for (int j=0;j<k;j++)
 //   {qq=sz[i][j];w=sz[i][k-j];if (j+j==k){if (w)--w;  ans+=qq*w/2;} else ans+=qq*w;   
  //  cout<<i<<" "<<j<<" "<<qq<<" "<<w<<endl;
  //      }
//}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}