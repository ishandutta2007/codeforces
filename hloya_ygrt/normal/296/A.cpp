#include <bits\stdc++.h>

using namespace std;
#define mp make_pair
#define f first
#define pb push_back
#define ll long long
#define s second

const int eps=1e-8,maxn=1e5;
   int srt[1000]={0};
int main()
{
    int n;
    scanf("%d",&n);
    
    for (int i=0;i<n;i++){
       int x;
       scanf("%d",&x);
       x--;
       
       srt[x]++;
       if (srt[x] > (n+1)/2){
         cout<<"NO";
         exit(0);
          
       }
    }
    
    cout<<"YES";
    return 0;
}